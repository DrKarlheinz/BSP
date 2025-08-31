// Copyright 2016 Open Source Robotics Foundation, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <chrono>
#include <functional>
#include <memory>

#include "custom_interface/msg/servo.hpp"
#include "rclcpp/rclcpp.hpp"

using namespace std::chrono_literals;

/* This example creates a subclass of Node and uses std::bind() to register a
 * member function as a callback from the timer. */

class ServoPulisher : public rclcpp::Node
{
    public:
    ServoPulisher() : Node("servo_publisher"), count_(0)
    {
        publisher_ = this->create_publisher<custom_interface::msg::Servo>(
            "servo_publisher", 10);
        timer_ = this->create_wall_timer(
            250ms, std::bind(&ServoPulisher::read_serial, this));
    }

    private:
    void read_serial()
    {
        // get values from gy87 sensor

        auto data         = custom_interface::msg::Servo();
        data.aileron_left = 1000.0;

        if (count_ == 10)
            direction_ = -1;
        if (count_ == 0)
            direction_ = 1;
        count_ += direction_;
        data.aileron_right = 1000.0 + (count_ * 100.0);
        data.elevator      = 1000.0;
        data.rudder        = 1000.0;
        RCLCPP_INFO(
            this->get_logger(),
            "Publishing:\n ax '%f' \n ay '%f' \n az '%f' \n gx '%f' \n ",
            data.aileron_left, data.aileron_right, data.elevator, data.rudder);
        publisher_->publish(data);
    }
    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<custom_interface::msg::Servo>::SharedPtr publisher_;
    size_t count_  = 0;
    int direction_ = 1;
};

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<ServoPulisher>());
    rclcpp::shutdown();
    return 0;
}
