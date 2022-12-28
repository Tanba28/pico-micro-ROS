// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from qtw_interfaces:msg/Sensor.idl
// generated code does not contain a copyright notice
#include "qtw_interfaces/msg/detail/sensor__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `stamp`
#include "builtin_interfaces/msg/detail/time__functions.h"
// Member `accel`
// Member `gyro`
// Member `mag`
#include "geometry_msgs/msg/detail/vector3__functions.h"

bool
qtw_interfaces__msg__Sensor__init(qtw_interfaces__msg__Sensor * msg)
{
  if (!msg) {
    return false;
  }
  // stamp
  if (!builtin_interfaces__msg__Time__init(&msg->stamp)) {
    qtw_interfaces__msg__Sensor__fini(msg);
    return false;
  }
  // accel
  if (!geometry_msgs__msg__Vector3__init(&msg->accel)) {
    qtw_interfaces__msg__Sensor__fini(msg);
    return false;
  }
  // gyro
  if (!geometry_msgs__msg__Vector3__init(&msg->gyro)) {
    qtw_interfaces__msg__Sensor__fini(msg);
    return false;
  }
  // mag
  if (!geometry_msgs__msg__Vector3__init(&msg->mag)) {
    qtw_interfaces__msg__Sensor__fini(msg);
    return false;
  }
  // pressure
  // temperature
  // front_tilt
  // rear_tilt
  return true;
}

void
qtw_interfaces__msg__Sensor__fini(qtw_interfaces__msg__Sensor * msg)
{
  if (!msg) {
    return;
  }
  // stamp
  builtin_interfaces__msg__Time__fini(&msg->stamp);
  // accel
  geometry_msgs__msg__Vector3__fini(&msg->accel);
  // gyro
  geometry_msgs__msg__Vector3__fini(&msg->gyro);
  // mag
  geometry_msgs__msg__Vector3__fini(&msg->mag);
  // pressure
  // temperature
  // front_tilt
  // rear_tilt
}

bool
qtw_interfaces__msg__Sensor__are_equal(const qtw_interfaces__msg__Sensor * lhs, const qtw_interfaces__msg__Sensor * rhs)
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
  // accel
  if (!geometry_msgs__msg__Vector3__are_equal(
      &(lhs->accel), &(rhs->accel)))
  {
    return false;
  }
  // gyro
  if (!geometry_msgs__msg__Vector3__are_equal(
      &(lhs->gyro), &(rhs->gyro)))
  {
    return false;
  }
  // mag
  if (!geometry_msgs__msg__Vector3__are_equal(
      &(lhs->mag), &(rhs->mag)))
  {
    return false;
  }
  // pressure
  if (lhs->pressure != rhs->pressure) {
    return false;
  }
  // temperature
  if (lhs->temperature != rhs->temperature) {
    return false;
  }
  // front_tilt
  if (lhs->front_tilt != rhs->front_tilt) {
    return false;
  }
  // rear_tilt
  if (lhs->rear_tilt != rhs->rear_tilt) {
    return false;
  }
  return true;
}

bool
qtw_interfaces__msg__Sensor__copy(
  const qtw_interfaces__msg__Sensor * input,
  qtw_interfaces__msg__Sensor * output)
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
  // accel
  if (!geometry_msgs__msg__Vector3__copy(
      &(input->accel), &(output->accel)))
  {
    return false;
  }
  // gyro
  if (!geometry_msgs__msg__Vector3__copy(
      &(input->gyro), &(output->gyro)))
  {
    return false;
  }
  // mag
  if (!geometry_msgs__msg__Vector3__copy(
      &(input->mag), &(output->mag)))
  {
    return false;
  }
  // pressure
  output->pressure = input->pressure;
  // temperature
  output->temperature = input->temperature;
  // front_tilt
  output->front_tilt = input->front_tilt;
  // rear_tilt
  output->rear_tilt = input->rear_tilt;
  return true;
}

qtw_interfaces__msg__Sensor *
qtw_interfaces__msg__Sensor__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  qtw_interfaces__msg__Sensor * msg = (qtw_interfaces__msg__Sensor *)allocator.allocate(sizeof(qtw_interfaces__msg__Sensor), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(qtw_interfaces__msg__Sensor));
  bool success = qtw_interfaces__msg__Sensor__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
qtw_interfaces__msg__Sensor__destroy(qtw_interfaces__msg__Sensor * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    qtw_interfaces__msg__Sensor__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
qtw_interfaces__msg__Sensor__Sequence__init(qtw_interfaces__msg__Sensor__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  qtw_interfaces__msg__Sensor * data = NULL;

  if (size) {
    data = (qtw_interfaces__msg__Sensor *)allocator.zero_allocate(size, sizeof(qtw_interfaces__msg__Sensor), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = qtw_interfaces__msg__Sensor__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        qtw_interfaces__msg__Sensor__fini(&data[i - 1]);
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
qtw_interfaces__msg__Sensor__Sequence__fini(qtw_interfaces__msg__Sensor__Sequence * array)
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
      qtw_interfaces__msg__Sensor__fini(&array->data[i]);
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

qtw_interfaces__msg__Sensor__Sequence *
qtw_interfaces__msg__Sensor__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  qtw_interfaces__msg__Sensor__Sequence * array = (qtw_interfaces__msg__Sensor__Sequence *)allocator.allocate(sizeof(qtw_interfaces__msg__Sensor__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = qtw_interfaces__msg__Sensor__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
qtw_interfaces__msg__Sensor__Sequence__destroy(qtw_interfaces__msg__Sensor__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    qtw_interfaces__msg__Sensor__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
qtw_interfaces__msg__Sensor__Sequence__are_equal(const qtw_interfaces__msg__Sensor__Sequence * lhs, const qtw_interfaces__msg__Sensor__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!qtw_interfaces__msg__Sensor__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
qtw_interfaces__msg__Sensor__Sequence__copy(
  const qtw_interfaces__msg__Sensor__Sequence * input,
  qtw_interfaces__msg__Sensor__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(qtw_interfaces__msg__Sensor);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    qtw_interfaces__msg__Sensor * data =
      (qtw_interfaces__msg__Sensor *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!qtw_interfaces__msg__Sensor__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          qtw_interfaces__msg__Sensor__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!qtw_interfaces__msg__Sensor__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
