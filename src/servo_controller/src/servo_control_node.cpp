
#include <memory>

#include "custom_interface/msg/gy87.hpp"
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
using std::placeholders::_1;

class ServoControllerNode : public rclcpp::Node
{
    public:
    ServoControllerNode() : Node("servo_control_node")
    {
        auto param_description = rcl_interfaces::msg::ParameterDescriptor{};
        param_description.description =
            "Modify Mode from start to glide to land";
        this->declare_parameter("flap_stage", "0");

        subscription_ = this->create_subscription<custom_interface::msg::Gy87>(
            "gy87_reader", 10,
            std::bind(&ServoControllerNode::topic_callback, this, _1));
    }

    private:
    void topic_callback(const custom_interface::msg::Gy87::SharedPtr data) const
    {
        std::string flight_stage =
            this->get_parameter("flap_stage").as_string();

        RCLCPP_INFO(this->get_logger(), "first data '%f' flight stage '%s'",
                    data->ax, flight_stage.c_str());
    }
    rclcpp::Subscription<custom_interface::msg::Gy87>::SharedPtr subscription_;
};

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<ServoControllerNode>());
    rclcpp::shutdown();
    return 0;
}