// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from custom_interface:msg/Servo.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACE__MSG__DETAIL__SERVO__STRUCT_HPP_
#define CUSTOM_INTERFACE__MSG__DETAIL__SERVO__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__custom_interface__msg__Servo __attribute__((deprecated))
#else
# define DEPRECATED__custom_interface__msg__Servo __declspec(deprecated)
#endif

namespace custom_interface
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Servo_
{
  using Type = Servo_<ContainerAllocator>;

  explicit Servo_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->servoleft = 0.0f;
      this->servoright = 0.0f;
      this->servobackleft = 0.0f;
      this->servobackright = 0.0f;
    }
  }

  explicit Servo_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->servoleft = 0.0f;
      this->servoright = 0.0f;
      this->servobackleft = 0.0f;
      this->servobackright = 0.0f;
    }
  }

  // field types and members
  using _servoleft_type =
    float;
  _servoleft_type servoleft;
  using _servoright_type =
    float;
  _servoright_type servoright;
  using _servobackleft_type =
    float;
  _servobackleft_type servobackleft;
  using _servobackright_type =
    float;
  _servobackright_type servobackright;

  // setters for named parameter idiom
  Type & set__servoleft(
    const float & _arg)
  {
    this->servoleft = _arg;
    return *this;
  }
  Type & set__servoright(
    const float & _arg)
  {
    this->servoright = _arg;
    return *this;
  }
  Type & set__servobackleft(
    const float & _arg)
  {
    this->servobackleft = _arg;
    return *this;
  }
  Type & set__servobackright(
    const float & _arg)
  {
    this->servobackright = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    custom_interface::msg::Servo_<ContainerAllocator> *;
  using ConstRawPtr =
    const custom_interface::msg::Servo_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<custom_interface::msg::Servo_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<custom_interface::msg::Servo_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      custom_interface::msg::Servo_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<custom_interface::msg::Servo_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      custom_interface::msg::Servo_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<custom_interface::msg::Servo_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<custom_interface::msg::Servo_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<custom_interface::msg::Servo_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__custom_interface__msg__Servo
    std::shared_ptr<custom_interface::msg::Servo_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__custom_interface__msg__Servo
    std::shared_ptr<custom_interface::msg::Servo_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Servo_ & other) const
  {
    if (this->servoleft != other.servoleft) {
      return false;
    }
    if (this->servoright != other.servoright) {
      return false;
    }
    if (this->servobackleft != other.servobackleft) {
      return false;
    }
    if (this->servobackright != other.servobackright) {
      return false;
    }
    return true;
  }
  bool operator!=(const Servo_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Servo_

// alias to use template instance with default allocator
using Servo =
  custom_interface::msg::Servo_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace custom_interface

#endif  // CUSTOM_INTERFACE__MSG__DETAIL__SERVO__STRUCT_HPP_
