// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from custom_interface:msg/Gy87.idl
// generated code does not contain a copyright notice
#include "custom_interface/msg/detail/gy87__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
custom_interface__msg__Gy87__init(custom_interface__msg__Gy87 * msg)
{
  if (!msg) {
    return false;
  }
  // ax
  // ay
  // az
  // gx
  // gy
  // gz
  return true;
}

void
custom_interface__msg__Gy87__fini(custom_interface__msg__Gy87 * msg)
{
  if (!msg) {
    return;
  }
  // ax
  // ay
  // az
  // gx
  // gy
  // gz
}

bool
custom_interface__msg__Gy87__are_equal(const custom_interface__msg__Gy87 * lhs, const custom_interface__msg__Gy87 * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // ax
  if (lhs->ax != rhs->ax) {
    return false;
  }
  // ay
  if (lhs->ay != rhs->ay) {
    return false;
  }
  // az
  if (lhs->az != rhs->az) {
    return false;
  }
  // gx
  if (lhs->gx != rhs->gx) {
    return false;
  }
  // gy
  if (lhs->gy != rhs->gy) {
    return false;
  }
  // gz
  if (lhs->gz != rhs->gz) {
    return false;
  }
  return true;
}

bool
custom_interface__msg__Gy87__copy(
  const custom_interface__msg__Gy87 * input,
  custom_interface__msg__Gy87 * output)
{
  if (!input || !output) {
    return false;
  }
  // ax
  output->ax = input->ax;
  // ay
  output->ay = input->ay;
  // az
  output->az = input->az;
  // gx
  output->gx = input->gx;
  // gy
  output->gy = input->gy;
  // gz
  output->gz = input->gz;
  return true;
}

custom_interface__msg__Gy87 *
custom_interface__msg__Gy87__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_interface__msg__Gy87 * msg = (custom_interface__msg__Gy87 *)allocator.allocate(sizeof(custom_interface__msg__Gy87), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(custom_interface__msg__Gy87));
  bool success = custom_interface__msg__Gy87__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
custom_interface__msg__Gy87__destroy(custom_interface__msg__Gy87 * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    custom_interface__msg__Gy87__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
custom_interface__msg__Gy87__Sequence__init(custom_interface__msg__Gy87__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_interface__msg__Gy87 * data = NULL;

  if (size) {
    data = (custom_interface__msg__Gy87 *)allocator.zero_allocate(size, sizeof(custom_interface__msg__Gy87), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = custom_interface__msg__Gy87__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        custom_interface__msg__Gy87__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
custom_interface__msg__Gy87__Sequence__fini(custom_interface__msg__Gy87__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      custom_interface__msg__Gy87__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

custom_interface__msg__Gy87__Sequence *
custom_interface__msg__Gy87__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_interface__msg__Gy87__Sequence * array = (custom_interface__msg__Gy87__Sequence *)allocator.allocate(sizeof(custom_interface__msg__Gy87__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = custom_interface__msg__Gy87__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
custom_interface__msg__Gy87__Sequence__destroy(custom_interface__msg__Gy87__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    custom_interface__msg__Gy87__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
custom_interface__msg__Gy87__Sequence__are_equal(const custom_interface__msg__Gy87__Sequence * lhs, const custom_interface__msg__Gy87__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!custom_interface__msg__Gy87__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
custom_interface__msg__Gy87__Sequence__copy(
  const custom_interface__msg__Gy87__Sequence * input,
  custom_interface__msg__Gy87__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(custom_interface__msg__Gy87);
    custom_interface__msg__Gy87 * data =
      (custom_interface__msg__Gy87 *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!custom_interface__msg__Gy87__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          custom_interface__msg__Gy87__fini(&data[i]);
        }
        free(data);
        return false;
      }
    }
    output->data = data;
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!custom_interface__msg__Gy87__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
