// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from qtw_interfaces:msg/Target.idl
// generated code does not contain a copyright notice
#include "qtw_interfaces/msg/detail/target__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `stamp`
#include "builtin_interfaces/msg/detail/time__functions.h"
// Member `pos`
// Member `euler`
#include "geometry_msgs/msg/detail/vector3__functions.h"

bool
qtw_interfaces__msg__Target__init(qtw_interfaces__msg__Target * msg)
{
  if (!msg) {
    return false;
  }
  // stamp
  if (!builtin_interfaces__msg__Time__init(&msg->stamp)) {
    qtw_interfaces__msg__Target__fini(msg);
    return false;
  }
  // pos
  if (!geometry_msgs__msg__Vector3__init(&msg->pos)) {
    qtw_interfaces__msg__Target__fini(msg);
    return false;
  }
  // euler
  if (!geometry_msgs__msg__Vector3__init(&msg->euler)) {
    qtw_interfaces__msg__Target__fini(msg);
    return false;
  }
  // tilt
  // value_1
  // value_2
  // value_3
  // value_4
  return true;
}

void
qtw_interfaces__msg__Target__fini(qtw_interfaces__msg__Target * msg)
{
  if (!msg) {
    return;
  }
  // stamp
  builtin_interfaces__msg__Time__fini(&msg->stamp);
  // pos
  geometry_msgs__msg__Vector3__fini(&msg->pos);
  // euler
  geometry_msgs__msg__Vector3__fini(&msg->euler);
  // tilt
  // value_1
  // value_2
  // value_3
  // value_4
}

bool
qtw_interfaces__msg__Target__are_equal(const qtw_interfaces__msg__Target * lhs, const qtw_interfaces__msg__Target * rhs)
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
  // pos
  if (!geometry_msgs__msg__Vector3__are_equal(
      &(lhs->pos), &(rhs->pos)))
  {
    return false;
  }
  // euler
  if (!geometry_msgs__msg__Vector3__are_equal(
      &(lhs->euler), &(rhs->euler)))
  {
    return false;
  }
  // tilt
  if (lhs->tilt != rhs->tilt) {
    return false;
  }
  // value_1
  if (lhs->value_1 != rhs->value_1) {
    return false;
  }
  // value_2
  if (lhs->value_2 != rhs->value_2) {
    return false;
  }
  // value_3
  if (lhs->value_3 != rhs->value_3) {
    return false;
  }
  // value_4
  if (lhs->value_4 != rhs->value_4) {
    return false;
  }
  return true;
}

bool
qtw_interfaces__msg__Target__copy(
  const qtw_interfaces__msg__Target * input,
  qtw_interfaces__msg__Target * output)
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
  // pos
  if (!geometry_msgs__msg__Vector3__copy(
      &(input->pos), &(output->pos)))
  {
    return false;
  }
  // euler
  if (!geometry_msgs__msg__Vector3__copy(
      &(input->euler), &(output->euler)))
  {
    return false;
  }
  // tilt
  output->tilt = input->tilt;
  // value_1
  output->value_1 = input->value_1;
  // value_2
  output->value_2 = input->value_2;
  // value_3
  output->value_3 = input->value_3;
  // value_4
  output->value_4 = input->value_4;
  return true;
}

qtw_interfaces__msg__Target *
qtw_interfaces__msg__Target__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  qtw_interfaces__msg__Target * msg = (qtw_interfaces__msg__Target *)allocator.allocate(sizeof(qtw_interfaces__msg__Target), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(qtw_interfaces__msg__Target));
  bool success = qtw_interfaces__msg__Target__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
qtw_interfaces__msg__Target__destroy(qtw_interfaces__msg__Target * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    qtw_interfaces__msg__Target__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
qtw_interfaces__msg__Target__Sequence__init(qtw_interfaces__msg__Target__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  qtw_interfaces__msg__Target * data = NULL;

  if (size) {
    data = (qtw_interfaces__msg__Target *)allocator.zero_allocate(size, sizeof(qtw_interfaces__msg__Target), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = qtw_interfaces__msg__Target__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        qtw_interfaces__msg__Target__fini(&data[i - 1]);
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
qtw_interfaces__msg__Target__Sequence__fini(qtw_interfaces__msg__Target__Sequence * array)
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
      qtw_interfaces__msg__Target__fini(&array->data[i]);
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

qtw_interfaces__msg__Target__Sequence *
qtw_interfaces__msg__Target__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  qtw_interfaces__msg__Target__Sequence * array = (qtw_interfaces__msg__Target__Sequence *)allocator.allocate(sizeof(qtw_interfaces__msg__Target__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = qtw_interfaces__msg__Target__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
qtw_interfaces__msg__Target__Sequence__destroy(qtw_interfaces__msg__Target__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    qtw_interfaces__msg__Target__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
qtw_interfaces__msg__Target__Sequence__are_equal(const qtw_interfaces__msg__Target__Sequence * lhs, const qtw_interfaces__msg__Target__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!qtw_interfaces__msg__Target__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
qtw_interfaces__msg__Target__Sequence__copy(
  const qtw_interfaces__msg__Target__Sequence * input,
  qtw_interfaces__msg__Target__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(qtw_interfaces__msg__Target);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    qtw_interfaces__msg__Target * data =
      (qtw_interfaces__msg__Target *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!qtw_interfaces__msg__Target__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          qtw_interfaces__msg__Target__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!qtw_interfaces__msg__Target__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
