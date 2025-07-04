// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from custom_interface:msg/Gy87.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACE__MSG__DETAIL__GY87__STRUCT_HPP_
#define CUSTOM_INTERFACE__MSG__DETAIL__GY87__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__custom_interface__msg__Gy87 __attribute__((deprecated))
#else
# define DEPRECATED__custom_interface__msg__Gy87 __declspec(deprecated)
#endif

namespace custom_interface
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Gy87_
{
  using Type = Gy87_<ContainerAllocator>;

  explicit Gy87_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->ax = 0.0f;
      this->ay = 0.0f;
      this->az = 0.0f;
      this->gx = 0.0f;
      this->gy = 0.0f;
      this->gz = 0.0f;
    }
  }

  explicit Gy87_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->ax = 0.0f;
      this->ay = 0.0f;
      this->az = 0.0f;
      this->gx = 0.0f;
      this->gy = 0.0f;
      this->gz = 0.0f;
    }
  }

  // field types and members
  using _ax_type =
    float;
  _ax_type ax;
  using _ay_type =
    float;
  _ay_type ay;
  using _az_type =
    float;
  _az_type az;
  using _gx_type =
    float;
  _gx_type gx;
  using _gy_type =
    float;
  _gy_type gy;
  using _gz_type =
    float;
  _gz_type gz;

  // setters for named parameter idiom
  Type & set__ax(
    const float & _arg)
  {
    this->ax = _arg;
    return *this;
  }
  Type & set__ay(
    const float & _arg)
  {
    this->ay = _arg;
    return *this;
  }
  Type & set__az(
    const float & _arg)
  {
    this->az = _arg;
    return *this;
  }
  Type & set__gx(
    const float & _arg)
  {
    this->gx = _arg;
    return *this;
  }
  Type & set__gy(
    const float & _arg)
  {
    this->gy = _arg;
    return *this;
  }
  Type & set__gz(
    const float & _arg)
  {
    this->gz = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    custom_interface::msg::Gy87_<ContainerAllocator> *;
  using ConstRawPtr =
    const custom_interface::msg::Gy87_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<custom_interface::msg::Gy87_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<custom_interface::msg::Gy87_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      custom_interface::msg::Gy87_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<custom_interface::msg::Gy87_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      custom_interface::msg::Gy87_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<custom_interface::msg::Gy87_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<custom_interface::msg::Gy87_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<custom_interface::msg::Gy87_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__custom_interface__msg__Gy87
    std::shared_ptr<custom_interface::msg::Gy87_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__custom_interface__msg__Gy87
    std::shared_ptr<custom_interface::msg::Gy87_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Gy87_ & other) const
  {
    if (this->ax != other.ax) {
      return false;
    }
    if (this->ay != other.ay) {
      return false;
    }
    if (this->az != other.az) {
      return false;
    }
    if (this->gx != other.gx) {
      return false;
    }
    if (this->gy != other.gy) {
      return false;
    }
    if (this->gz != other.gz) {
      return false;
    }
    return true;
  }
  bool operator!=(const Gy87_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Gy87_

// alias to use template instance with default allocator
using Gy87 =
  custom_interface::msg::Gy87_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace custom_interface

#endif  // CUSTOM_INTERFACE__MSG__DETAIL__GY87__STRUCT_HPP_
