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
#include <string>

#include "custom_interface/msg/gy87.hpp"
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/detail/string__struct.hpp"
#include "std_msgs/msg/string.hpp"
#include "mpu6050.h"

using namespace std::chrono_literals;

/* This example creates a subclass of Node and uses std::bind() to register a
 * member function as a callback from the timer. */

class Gy87Reader : public rclcpp::Node
{
    public:
    Gy87Reader() : Node("gy87_reader"), count_(0)
    {
        publisher_ = this->create_publisher<custom_interface::msg::Gy87>(
            "gy87_reader", 10);
        timer_ = this->create_wall_timer(
            1000ms, std::bind(&Gy87Reader::read_serial, this));

        mpu.setDebug(false);
        fflush(stdout);

        if (!mpu.whoAmI())
        {
            printf("\nERROR: Cannot find the MPU6050 sensor!\n");
            rclcpp::shutdown();
        }

        mpu.initialize();
    }

    private:
    void read_serial()
    {
        int16_t ax, ay, az;
        int16_t gx, gy, gz;

        // get values from gy87 sensor
        mpu.getAcceleration(&ax, &ay, &az);
        mpu.getRotation(&gx, &gy, &gz);

        auto message = custom_interface::msg::Gy87();
        message.ax   = (float)ax / 16384.0;
        message.ay   = (float)ay / 16384.0;
        message.az   = (float)az / 16384.0;

        message.gx = (float)gx / 131.0;
        message.gy = (float)gy / 131.0;
        message.gz = (float)gz / 131.0;
        RCLCPP_INFO(this->get_logger(),
                    "Publishing:\n ax '%f' \n ay '%f' \n az '%f' \n gx '%f' \n "
                    "gy '%f' \n gz '%f'",
                    message.ax, message.ay, message.az, message.gx, message.gy,
                    message.gz);
        publisher_->publish(message);
    }
    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<custom_interface::msg::Gy87>::SharedPtr publisher_;
    size_t count_;
    MPU6050 mpu;
};

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<Gy87Reader>());
    rclcpp::shutdown();
    return 0;
}
