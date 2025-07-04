// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from custom_interface:msg/Gy87.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACE__MSG__DETAIL__GY87__STRUCT_H_
#define CUSTOM_INTERFACE__MSG__DETAIL__GY87__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Struct defined in msg/Gy87 in the package custom_interface.
typedef struct custom_interface__msg__Gy87
{
  float ax;
  float ay;
  float az;
  float gx;
  float gy;
  float gz;
} custom_interface__msg__Gy87;

// Struct for a sequence of custom_interface__msg__Gy87.
typedef struct custom_interface__msg__Gy87__Sequence
{
  custom_interface__msg__Gy87 * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_interface__msg__Gy87__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CUSTOM_INTERFACE__MSG__DETAIL__GY87__STRUCT_H_
