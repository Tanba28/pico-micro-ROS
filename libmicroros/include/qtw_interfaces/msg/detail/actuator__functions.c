// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from qtw_interfaces:msg/Actuator.idl
// generated code does not contain a copyright notice
#include "qtw_interfaces/msg/detail/actuator__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"

bool
qtw_interfaces__msg__Actuator__init(qtw_interfaces__msg__Actuator * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    qtw_interfaces__msg__Actuator__fini(msg);
    return false;
  }
  // tilt_front
  // tilt_back
  // flap_front_right
  // flap_front_left
  // flap_back_right
  // flap_back_left
  // rudder
  // thrust_front_right
  // thrust_front_left
  // thrust_back_right
  // thrust_back_left
  return true;
}

void
qtw_interfaces__msg__Actuator__fini(qtw_interfaces__msg__Actuator * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // tilt_front
  // tilt_back
  // flap_front_right
  // flap_front_left
  // flap_back_right
  // flap_back_left
  // rudder
  // thrust_front_right
  // thrust_front_left
  // thrust_back_right
  // thrust_back_left
}

bool
qtw_interfaces__msg__Actuator__are_equal(const qtw_interfaces__msg__Actuator * lhs, const qtw_interfaces__msg__Actuator * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__are_equal(
      &(lhs->header), &(rhs->header)))
  {
    return false;
  }
  // tilt_front
  if (lhs->tilt_front != rhs->tilt_front) {
    return false;
  }
  // tilt_back
  if (lhs->tilt_back != rhs->tilt_back) {
    return false;
  }
  // flap_front_right
  if (lhs->flap_front_right != rhs->flap_front_right) {
    return false;
  }
  // flap_front_left
  if (lhs->flap_front_left != rhs->flap_front_left) {
    return false;
  }
  // flap_back_right
  if (lhs->flap_back_right != rhs->flap_back_right) {
    return false;
  }
  // flap_back_left
  if (lhs->flap_back_left != rhs->flap_back_left) {
    return false;
  }
  // rudder
  if (lhs->rudder != rhs->rudder) {
    return false;
  }
  // thrust_front_right
  if (lhs->thrust_front_right != rhs->thrust_front_right) {
    return false;
  }
  // thrust_front_left
  if (lhs->thrust_front_left != rhs->thrust_front_left) {
    return false;
  }
  // thrust_back_right
  if (lhs->thrust_back_right != rhs->thrust_back_right) {
    return false;
  }
  // thrust_back_left
  if (lhs->thrust_back_left != rhs->thrust_back_left) {
    return false;
  }
  return true;
}

bool
qtw_interfaces__msg__Actuator__copy(
  const qtw_interfaces__msg__Actuator * input,
  qtw_interfaces__msg__Actuator * output)
{
  if (!input || !output) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__copy(
      &(input->header), &(output->header)))
  {
    return false;
  }
  // tilt_front
  output->tilt_front = input->tilt_front;
  // tilt_back
  output->tilt_back = input->tilt_back;
  // flap_front_right
  output->flap_front_right = input->flap_front_right;
  // flap_front_left
  output->flap_front_left = input->flap_front_left;
  // flap_back_right
  output->flap_back_right = input->flap_back_right;
  // flap_back_left
  output->flap_back_left = input->flap_back_left;
  // rudder
  output->rudder = input->rudder;
  // thrust_front_right
  output->thrust_front_right = input->thrust_front_right;
  // thrust_front_left
  output->thrust_front_left = input->thrust_front_left;
  // thrust_back_right
  output->thrust_back_right = input->thrust_back_right;
  // thrust_back_left
  output->thrust_back_left = input->thrust_back_left;
  return true;
}

qtw_interfaces__msg__Actuator *
qtw_interfaces__msg__Actuator__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  qtw_interfaces__msg__Actuator * msg = (qtw_interfaces__msg__Actuator *)allocator.allocate(sizeof(qtw_interfaces__msg__Actuator), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(qtw_interfaces__msg__Actuator));
  bool success = qtw_interfaces__msg__Actuator__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
qtw_interfaces__msg__Actuator__destroy(qtw_interfaces__msg__Actuator * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    qtw_interfaces__msg__Actuator__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
qtw_interfaces__msg__Actuator__Sequence__init(qtw_interfaces__msg__Actuator__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  qtw_interfaces__msg__Actuator * data = NULL;

  if (size) {
    data = (qtw_interfaces__msg__Actuator *)allocator.zero_allocate(size, sizeof(qtw_interfaces__msg__Actuator), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = qtw_interfaces__msg__Actuator__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        qtw_interfaces__msg__Actuator__fini(&data[i - 1]);
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
qtw_interfaces__msg__Actuator__Sequence__fini(qtw_interfaces__msg__Actuator__Sequence * array)
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
      qtw_interfaces__msg__Actuator__fini(&array->data[i]);
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

qtw_interfaces__msg__Actuator__Sequence *
qtw_interfaces__msg__Actuator__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  qtw_interfaces__msg__Actuator__Sequence * array = (qtw_interfaces__msg__Actuator__Sequence *)allocator.allocate(sizeof(qtw_interfaces__msg__Actuator__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = qtw_interfaces__msg__Actuator__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
qtw_interfaces__msg__Actuator__Sequence__destroy(qtw_interfaces__msg__Actuator__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    qtw_interfaces__msg__Actuator__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
qtw_interfaces__msg__Actuator__Sequence__are_equal(const qtw_interfaces__msg__Actuator__Sequence * lhs, const qtw_interfaces__msg__Actuator__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!qtw_interfaces__msg__Actuator__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
qtw_interfaces__msg__Actuator__Sequence__copy(
  const qtw_interfaces__msg__Actuator__Sequence * input,
  qtw_interfaces__msg__Actuator__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(qtw_interfaces__msg__Actuator);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    qtw_interfaces__msg__Actuator * data =
      (qtw_interfaces__msg__Actuator *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!qtw_interfaces__msg__Actuator__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          qtw_interfaces__msg__Actuator__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!qtw_interfaces__msg__Actuator__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
