#include "custom_interface/msg/servo.hpp"
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include <iostream>
#include <memory>
#include <pigpiod_if2.h>
#include <unistd.h>
using std::placeholders::_1;

class ServoControllerNode : public rclcpp::Node
{

    rclcpp::Subscription<custom_interface::msg::Servo>::SharedPtr subscription_;
    int aileron_right_ ;
    int aileron_left_  ;
    int elevator_      ;
    int rudder_        ;
    int pi_;

    public:
    ServoControllerNode() : Node("servo_control_node")
    {

        subscription_ = this->create_subscription<custom_interface::msg::Servo>(
            "servo_publisher", 10,
            std::bind(&ServoControllerNode::topic_callback, this, _1));

        pi_ = pigpio_start(nullptr, nullptr); // Connect to local pigpiod
        if (pi_ < 0)
        {
            RCLCPP_FATAL(this->get_logger(), "Failed to connect to pigpiod");
            rclcpp::shutdown();
            return;
        }

        aileron_right_ = 17;
        aileron_left_  = 27;
        elevator_      = 22;
        rudder_        = 23;

        set_mode(pi_, aileron_right_, PI_OUTPUT);
        set_PWM_frequency(pi_, aileron_right_, 50);

        set_mode(pi_, aileron_left_, PI_OUTPUT);
        set_PWM_frequency(pi_, aileron_left_, 50); 

        set_mode(pi_, elevator_, PI_OUTPUT);
        set_PWM_frequency(pi_, elevator_, 50); 

        set_mode(pi_, rudder_, PI_OUTPUT);
        set_PWM_frequency(pi_, rudder_, 50); 

        RCLCPP_INFO(this->get_logger(), "Servo node initialized.");
    }

    ~ServoControllerNode()
    {
        set_servo_pulsewidth(pi_, aileron_right_, 0); // Stop PWM
        set_servo_pulsewidth(pi_, aileron_left_, 0);
        set_servo_pulsewidth(pi_, elevator_, 0);
        set_servo_pulsewidth(pi_, rudder_, 0);
        RCLCPP_INFO(this->get_logger(), "Serv gt shut down why??");
        pigpio_stop(pi_); // Disconnect from pigpiod
    }

    private:
    void
    topic_callback(const custom_interface::msg::Servo::SharedPtr data) const
    {
        int aileron_left_pwm  = 1000.0;
        int aileron_right_pwm = 1000.0;
        int elevator_pwm      = 1000.0;
        int rudder_pwm        = 1000.0;

        aileron_left_pwm  = data->aileron_left;
        aileron_right_pwm = data->aileron_right;
        elevator_pwm      = data->elevator;
        rudder_pwm        = data->rudder;

        set_servo_pulsewidth(pi_, aileron_left_, aileron_left_pwm);
        set_servo_pulsewidth(pi_, aileron_right_, aileron_right_pwm);
        set_servo_pulsewidth(pi_, elevator_, elevator_pwm);
        set_servo_pulsewidth(pi_, rudder_, rudder_pwm);
        
        RCLCPP_INFO(this->get_logger(), "PWM set to %d us", aileron_left_pwm);
        RCLCPP_INFO(this->get_logger(), "PWM set to %d us", aileron_right_pwm);
        RCLCPP_INFO(this->get_logger(), "PWM set to %d us", elevator_pwm);
        RCLCPP_INFO(this->get_logger(), "PWM set to %d us", rudder_pwm);
    }
};

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<ServoControllerNode>());
    rclcpp::shutdown();
    return 0;
}
