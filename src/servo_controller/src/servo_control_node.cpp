#include "custom_interface/msg/servo.hpp"
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include <iostream>
#include <memory>
// #include <pigpiod_if2.h>
#include <unistd.h>
using std::placeholders::_1;

class ServoControllerNode : public rclcpp::Node
{
    public:
    ServoControllerNode() : Node("servo_control_node")
    {

        subscription_ = this->create_subscription<custom_interface::msg::Servo>(
            "servo_publisher", 10,
            std::bind(&ServoControllerNode::topic_callback, this, _1));

        // pi_ = pigpio_start(nullptr, nullptr); // Connect to local pigpiod
        // if (pi_ < 0)
        // {
        //     RCLCPP_FATAL(this->get_logger(), "Failed to connect to pigpiod");
        //     rclcpp::shutdown();
        //     return;
        // }

        // servo_pin_ = 17;
        // set_mode(pi_, servo_pin_, PI_OUTPUT);
        // set_PWM_frequency(pi_, servo_pin_, 50); // 50Hz

        RCLCPP_INFO(this->get_logger(), "Servo node initialized.");
    }

    ~ServoControllerNode()
    {
        // set_servo_pulsewidth(pi_, servo_pin_, 0); // Stop PWM
        RCLCPP_INFO(this->get_logger(), "Serv gt shut down why??");
        // pigpio_stop(pi_); // Disconnect from pigpiod
    }

    private:
    void
    topic_callback(const custom_interface::msg::Servo::SharedPtr data) const
    {

        RCLCPP_INFO(this->get_logger(), "first data '%f' ", data->servoright);

        // int pwm_us = 1450; // Default (center)

        // set_servo_pulsewidth(pi_, servo_pin_, pwm_us);
        RCLCPP_INFO(this->get_logger(), "PWM set to %d us", pwm_us);
    }
    rclcpp::Subscription<custom_interface::msg::Servo>::SharedPtr subscription_;
    int servo_pin_;
    int pi_;
};

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<ServoControllerNode>());
    rclcpp::shutdown();
    return 0;
}
