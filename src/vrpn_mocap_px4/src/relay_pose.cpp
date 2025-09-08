#include <chrono>
#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/pose.hpp"
#include "geometry_msgs/msg/pose_stamped.hpp"
#include "custom_interface/msg/vehicle_odometry.hpp"

using std::placeholders::_1;

using namespace std::chrono_literals;

class RelayPose : public rclcpp::Node
{
  public:
    RelayPose()
    : Node("relay_pose")
    {
      //Declaring parameters and setting them to default values
      this->declare_parameter("source","/vrpn/hummingbird/pose");
      this->declare_parameter("sink","/fmu/in/vehicle_visual_odometry");

      //Resetting parameters as provided by the user
      std::string source = this->get_parameter("source").as_string();
      std::string sink = this->get_parameter("sink").as_string();

      //Printing source and sink topics
      std::cout << "Sourcing pose from: " << source << std::endl;
      std::cout << "Publishing pose to: " << sink << std::endl;

      //Create subscriber for source and publisher for sink
      rt_sub_pose = this->create_subscription<geometry_msgs::msg::PoseStamped>(source, 10, std::bind(&RelayPose::relay_pose_callback, this, _1));
      rt_pub_odom = this->create_publisher<custom_interface::msg::VehicleOdometry>(sink,10);
    }
  
  private:
    void relay_pose_callback(const geometry_msgs::msg::PoseStamped::SharedPtr msg) const
    {
      //Read mocap pose in FLU and publish to fmu in NED
      //Declare odometry message for publication
      auto pub_odom_msg = custom_interface::msg::VehicleOdometry();

      //TimeStamp
      pub_odom_msg.timestamp = rclcpp::Clock(RCL_ROS_TIME).now().nanoseconds()/1000;
      pub_odom_msg.timestamp_sample = pub_odom_msg.timestamp;

      //Position
      pub_odom_msg.position[0] =  msg->pose.position.x;
      pub_odom_msg.position[1] = -msg->pose.position.y;
      pub_odom_msg.position[2] = -msg->pose.position.z;
      pub_odom_msg.position_variance[0] = 1e-6;
      pub_odom_msg.position_variance[1] = 1e-6;
      pub_odom_msg.position_variance[2] = 1e-6;
      
      //Orientation (quaternion)
      pub_odom_msg.q[0] =  msg->pose.orientation.w;
      pub_odom_msg.q[1] =  msg->pose.orientation.x;
      pub_odom_msg.q[2] = -msg->pose.orientation.y;
      pub_odom_msg.q[3] = -msg->pose.orientation.z;
      pub_odom_msg.orientation_variance[0] = 1e-6;
      pub_odom_msg.orientation_variance[1] = 1e-6;
      pub_odom_msg.orientation_variance[2] = 1e-6;

      //Unavailable velocity and angular velocity published as NAN 
      pub_odom_msg.velocity[0] = NAN;
      pub_odom_msg.velocity[1] = NAN;
      pub_odom_msg.velocity[2] = NAN;
      //pub_odom_msg.velocity_variance[0] = 1e-6;
      //pub_odom_msg.velocity_variance[1] = 1e-6;
      //pub_odom_msg.velocity_variance[2] = 1e-6;
      pub_odom_msg.angular_velocity[0] = NAN;
      pub_odom_msg.angular_velocity[1] = NAN;
      pub_odom_msg.angular_velocity[2] = NAN;

      //Setting the inertial frame to NED
      pub_odom_msg.pose_frame = pub_odom_msg.POSE_FRAME_NED;
      pub_odom_msg.velocity_frame = pub_odom_msg.VELOCITY_FRAME_NED;

      //pub_odom_msg.quality = 10;

      //Publish the message
      rt_pub_odom->publish(pub_odom_msg);
    }

  rclcpp::Subscription<geometry_msgs::msg::PoseStamped>::SharedPtr rt_sub_pose;
  rclcpp::Publisher<custom_interface::msg::VehicleOdometry>::SharedPtr rt_pub_odom;
};

int main(int argc, char ** argv)
{
  std::cout << "\nIn case of error, run or launch the node the following ways. Replace source and sink topics accordingly." << std::endl;
  std::cout << "ros2 run vrpn_mocap_px4 relay_pose --ros-args -p source:=/vrpn/hummingbird/pose -p sink:=/fmu/in/vehicle_visual_odometry" << std::endl;
  std::cout << "ros2 launch vrpn_mocap_px4 launch.yaml source:=/vrpn/hummingbird/pose sink:=/fmu/in/vehicle_visual_odometry\n" << std::endl;
  
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<RelayPose>());
  rclcpp::shutdown();
  
  return 0;
}

//ST21MT61124
