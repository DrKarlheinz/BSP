// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from custom_interface:msg/Servo.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACE__MSG__DETAIL__SERVO__BUILDER_HPP_
#define CUSTOM_INTERFACE__MSG__DETAIL__SERVO__BUILDER_HPP_

#include "custom_interface/msg/detail/servo__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace custom_interface
{

namespace msg
{

namespace builder
{

class Init_Servo_servobackright
{
public:
  explicit Init_Servo_servobackright(::custom_interface::msg::Servo & msg)
  : msg_(msg)
  {}
  ::custom_interface::msg::Servo servobackright(::custom_interface::msg::Servo::_servobackright_type arg)
  {
    msg_.servobackright = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_interface::msg::Servo msg_;
};

class Init_Servo_servobackleft
{
public:
  explicit Init_Servo_servobackleft(::custom_interface::msg::Servo & msg)
  : msg_(msg)
  {}
  Init_Servo_servobackright servobackleft(::custom_interface::msg::Servo::_servobackleft_type arg)
  {
    msg_.servobackleft = std::move(arg);
    return Init_Servo_servobackright(msg_);
  }

private:
  ::custom_interface::msg::Servo msg_;
};

class Init_Servo_servoright
{
public:
  explicit Init_Servo_servoright(::custom_interface::msg::Servo & msg)
  : msg_(msg)
  {}
  Init_Servo_servobackleft servoright(::custom_interface::msg::Servo::_servoright_type arg)
  {
    msg_.servoright = std::move(arg);
    return Init_Servo_servobackleft(msg_);
  }

private:
  ::custom_interface::msg::Servo msg_;
};

class Init_Servo_servoleft
{
public:
  Init_Servo_servoleft()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Servo_servoright servoleft(::custom_interface::msg::Servo::_servoleft_type arg)
  {
    msg_.servoleft = std::move(arg);
    return Init_Servo_servoright(msg_);
  }

private:
  ::custom_interface::msg::Servo msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_interface::msg::Servo>()
{
  return custom_interface::msg::builder::Init_Servo_servoleft();
}

}  // namespace custom_interface

#endif  // CUSTOM_INTERFACE__MSG__DETAIL__SERVO__BUILDER_HPP_
