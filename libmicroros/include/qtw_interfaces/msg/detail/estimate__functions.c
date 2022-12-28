// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from qtw_interfaces:msg/Estimate.idl
// generated code does not contain a copyright notice
#include "qtw_interfaces/msg/detail/estimate__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `stamp`
#include "builtin_interfaces/msg/detail/time__functions.h"
// Member `pose`
#include "geometry_msgs/msg/detail/pose__functions.h"
// Member `twist`
#include "geometry_msgs/msg/detail/twist__functions.h"

bool
qtw_interfaces__msg__Estimate__init(qtw_interfaces__msg__Estimate * msg)
{
  if (!msg) {
    return false;
  }
  // stamp
  if (!builtin_interfaces__msg__Time__init(&msg->stamp)) {
    qtw_interfaces__msg__Estimate__fini(msg);
    return false;
  }
  // pose
  if (!geometry_msgs__msg__Pose__init(&msg->pose)) {
    qtw_interfaces__msg__Estimate__fini(msg);
    return false;
  }
  // twist
  if (!geometry_msgs__msg__Twist__init(&msg->twist)) {
    qtw_interfaces__msg__Estimate__fini(msg);
    return false;
  }
  return true;
}

void
qtw_interfaces__msg__Estimate__fini(qtw_interfaces__msg__Estimate * msg)
{
  if (!msg) {
    return;
  }
  // stamp
  builtin_interfaces__msg__Time__fini(&msg->stamp);
  // pose
  geometry_msgs__msg__Pose__fini(&msg->pose);
  // twist
  geometry_msgs__msg__Twist__fini(&msg->twist);
}

bool
qtw_interfaces__msg__Estimate__are_equal(const qtw_interfaces__msg__Estimate * lhs, const qtw_interfaces__msg__Estimate * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // stamp
  if (!builtin_interfaces__msg__Time__are_equal(
      &(lhs->stamp), &(rhs->stamp)))
  {
    return false;
  }
  // pose
  if (!geometry_msgs__msg__Pose__are_equal(
      &(lhs->pose), &(rhs->pose)))
  {
    return false;
  }
  // twist
  if (!geometry_msgs__msg__Twist__are_equal(
      &(lhs->twist), &(rhs->twist)))
  {
    return false;
  }
  return true;
}

bool
qtw_interfaces__msg__Estimate__copy(
  const qtw_interfaces__msg__Estimate * input,
  qtw_interfaces__msg__Estimate * output)
{
  if (!input || !output) {
    return false;
  }
  // stamp
  if (!builtin_interfaces__msg__Time__copy(
      &(input->stamp), &(output->stamp)))
  {
    return false;
  }
  // pose
  if (!geometry_msgs__msg__Pose__copy(
      &(input->pose), &(output->pose)))
  {
    return false;
  }
  // twist
  if (!geometry_msgs__msg__Twist__copy(
      &(input->twist), &(output->twist)))
  {
    return false;
  }
  return true;
}

qtw_interfaces__msg__Estimate *
qtw_interfaces__msg__Estimate__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  qtw_interfaces__msg__Estimate * msg = (qtw_interfaces__msg__Estimate *)allocator.allocate(sizeof(qtw_interfaces__msg__Estimate), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(qtw_interfaces__msg__Estimate));
  bool success = qtw_interfaces__msg__Estimate__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
qtw_interfaces__msg__Estimate__destroy(qtw_interfaces__msg__Estimate * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    qtw_interfaces__msg__Estimate__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
qtw_interfaces__msg__Estimate__Sequence__init(qtw_interfaces__msg__Estimate__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  qtw_interfaces__msg__Estimate * data = NULL;

  if (size) {
    data = (qtw_interfaces__msg__Estimate *)allocator.zero_allocate(size, sizeof(qtw_interfaces__msg__Estimate), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = qtw_interfaces__msg__Estimate__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        qtw_interfaces__msg__Estimate__fini(&data[i - 1]);
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
qtw_interfaces__msg__Estimate__Sequence__fini(qtw_interfaces__msg__Estimate__Sequence * array)
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
      qtw_interfaces__msg__Estimate__fini(&array->data[i]);
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

qtw_interfaces__msg__Estimate__Sequence *
qtw_interfaces__msg__Estimate__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  qtw_interfaces__msg__Estimate__Sequence * array = (qtw_interfaces__msg__Estimate__Sequence *)allocator.allocate(sizeof(qtw_interfaces__msg__Estimate__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = qtw_interfaces__msg__Estimate__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
qtw_interfaces__msg__Estimate__Sequence__destroy(qtw_interfaces__msg__Estimate__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    qtw_interfaces__msg__Estimate__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
qtw_interfaces__msg__Estimate__Sequence__are_equal(const qtw_interfaces__msg__Estimate__Sequence * lhs, const qtw_interfaces__msg__Estimate__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!qtw_interfaces__msg__Estimate__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
qtw_interfaces__msg__Estimate__Sequence__copy(
  const qtw_interfaces__msg__Estimate__Sequence * input,
  qtw_interfaces__msg__Estimate__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(qtw_interfaces__msg__Estimate);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    qtw_interfaces__msg__Estimate * data =
      (qtw_interfaces__msg__Estimate *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!qtw_interfaces__msg__Estimate__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          qtw_interfaces__msg__Estimate__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!qtw_interfaces__msg__Estimate__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
