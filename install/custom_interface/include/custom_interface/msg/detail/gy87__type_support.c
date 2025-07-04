// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from custom_interface:msg/Gy87.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "custom_interface/msg/detail/gy87__rosidl_typesupport_introspection_c.h"
#include "custom_interface/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "custom_interface/msg/detail/gy87__functions.h"
#include "custom_interface/msg/detail/gy87__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void Gy87__rosidl_typesupport_introspection_c__Gy87_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  custom_interface__msg__Gy87__init(message_memory);
}

void Gy87__rosidl_typesupport_introspection_c__Gy87_fini_function(void * message_memory)
{
  custom_interface__msg__Gy87__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember Gy87__rosidl_typesupport_introspection_c__Gy87_message_member_array[6] = {
  {
    "ax",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(custom_interface__msg__Gy87, ax),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "ay",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(custom_interface__msg__Gy87, ay),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "az",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(custom_interface__msg__Gy87, az),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "gx",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(custom_interface__msg__Gy87, gx),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "gy",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(custom_interface__msg__Gy87, gy),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "gz",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(custom_interface__msg__Gy87, gz),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers Gy87__rosidl_typesupport_introspection_c__Gy87_message_members = {
  "custom_interface__msg",  // message namespace
  "Gy87",  // message name
  6,  // number of fields
  sizeof(custom_interface__msg__Gy87),
  Gy87__rosidl_typesupport_introspection_c__Gy87_message_member_array,  // message members
  Gy87__rosidl_typesupport_introspection_c__Gy87_init_function,  // function to initialize message memory (memory has to be allocated)
  Gy87__rosidl_typesupport_introspection_c__Gy87_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t Gy87__rosidl_typesupport_introspection_c__Gy87_message_type_support_handle = {
  0,
  &Gy87__rosidl_typesupport_introspection_c__Gy87_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_custom_interface
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, custom_interface, msg, Gy87)() {
  if (!Gy87__rosidl_typesupport_introspection_c__Gy87_message_type_support_handle.typesupport_identifier) {
    Gy87__rosidl_typesupport_introspection_c__Gy87_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &Gy87__rosidl_typesupport_introspection_c__Gy87_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
