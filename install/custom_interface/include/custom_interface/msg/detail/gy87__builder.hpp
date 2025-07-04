// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from custom_interface:msg/Gy87.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACE__MSG__DETAIL__GY87__BUILDER_HPP_
#define CUSTOM_INTERFACE__MSG__DETAIL__GY87__BUILDER_HPP_

#include "custom_interface/msg/detail/gy87__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace custom_interface
{

namespace msg
{

namespace builder
{

class Init_Gy87_gz
{
public:
  explicit Init_Gy87_gz(::custom_interface::msg::Gy87 & msg)
  : msg_(msg)
  {}
  ::custom_interface::msg::Gy87 gz(::custom_interface::msg::Gy87::_gz_type arg)
  {
    msg_.gz = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_interface::msg::Gy87 msg_;
};

class Init_Gy87_gy
{
public:
  explicit Init_Gy87_gy(::custom_interface::msg::Gy87 & msg)
  : msg_(msg)
  {}
  Init_Gy87_gz gy(::custom_interface::msg::Gy87::_gy_type arg)
  {
    msg_.gy = std::move(arg);
    return Init_Gy87_gz(msg_);
  }

private:
  ::custom_interface::msg::Gy87 msg_;
};

class Init_Gy87_gx
{
public:
  explicit Init_Gy87_gx(::custom_interface::msg::Gy87 & msg)
  : msg_(msg)
  {}
  Init_Gy87_gy gx(::custom_interface::msg::Gy87::_gx_type arg)
  {
    msg_.gx = std::move(arg);
    return Init_Gy87_gy(msg_);
  }

private:
  ::custom_interface::msg::Gy87 msg_;
};

class Init_Gy87_az
{
public:
  explicit Init_Gy87_az(::custom_interface::msg::Gy87 & msg)
  : msg_(msg)
  {}
  Init_Gy87_gx az(::custom_interface::msg::Gy87::_az_type arg)
  {
    msg_.az = std::move(arg);
    return Init_Gy87_gx(msg_);
  }

private:
  ::custom_interface::msg::Gy87 msg_;
};

class Init_Gy87_ay
{
public:
  explicit Init_Gy87_ay(::custom_interface::msg::Gy87 & msg)
  : msg_(msg)
  {}
  Init_Gy87_az ay(::custom_interface::msg::Gy87::_ay_type arg)
  {
    msg_.ay = std::move(arg);
    return Init_Gy87_az(msg_);
  }

private:
  ::custom_interface::msg::Gy87 msg_;
};

class Init_Gy87_ax
{
public:
  Init_Gy87_ax()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Gy87_ay ax(::custom_interface::msg::Gy87::_ax_type arg)
  {
    msg_.ax = std::move(arg);
    return Init_Gy87_ay(msg_);
  }

private:
  ::custom_interface::msg::Gy87 msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_interface::msg::Gy87>()
{
  return custom_interface::msg::builder::Init_Gy87_ax();
}

}  // namespace custom_interface

#endif  // CUSTOM_INTERFACE__MSG__DETAIL__GY87__BUILDER_HPP_
