#include "px4_msgs/msg/vehicle_odometry.hpp"
#include "rclcpp/rclcpp.hpp"
#include <chrono>
#include <fstream>
#include <iostream>
#include <string>

using namespace std::chrono_literals;

class OdometryLogger : public rclcpp::Node
{
    public:
    OdometryLogger() : Node("movement_logger")
    {
        // Create a subscription to the vehicle visual odometry topic
        subscription_ =
            this->create_subscription<px4_msgs::msg::VehicleOdometry>(
                "/fmu/in/vehicle_visual_odometry", 10,
                std::bind(&OdometryLogger::odometry_callback, this,
                          std::placeholders::_1));

        // Open the CSV file for logging
        log_file_.open("odometry_log.csv", std::ios::out | std::ios::app);
        if (!log_file_.is_open())
        {
            RCLCPP_ERROR(this->get_logger(), "Failed to open log file");
        }
        else
        {
            log_file_
                << "timestamp,position_x,position_y,position_z,orientation_w,"
                   "orientation_x,orientation_y,orientation_z\n";
        }
    }

    ~OdometryLogger()
    {
        if (log_file_.is_open())
        {
            log_file_.close();
        }
    }

    private:
    void
    odometry_callback(const px4_msgs::msg::VehicleOdometry::SharedPtr msg) const
    {
        if (log_file_.is_open())
        {
            log_file_ << msg->timestamp << "," << msg->position[0] << ","
                      << msg->position[1] << "," << msg->position[2] << ","
                      << msg->q[0] << "," << msg->q[1] << "," << msg->q[2]
                      << "," << msg->q[3] << "\n";
        }
    }

    rclcpp::Subscription<px4_msgs::msg::VehicleOdometry>::SharedPtr
        subscription_;
    mutable std::ofstream log_file_;
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<OdometryLogger>());
    rclcpp::shutdown();
    return 0;
}