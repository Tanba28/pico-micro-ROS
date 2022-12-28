// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from qtw_interfaces:srv/ChangeArmMode.idl
// generated code does not contain a copyright notice
#include "qtw_interfaces/srv/detail/change_arm_mode__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

bool
qtw_interfaces__srv__ChangeArmMode_Request__init(qtw_interfaces__srv__ChangeArmMode_Request * msg)
{
  if (!msg) {
    return false;
  }
  // order
  return true;
}

void
qtw_interfaces__srv__ChangeArmMode_Request__fini(qtw_interfaces__srv__ChangeArmMode_Request * msg)
{
  if (!msg) {
    return;
  }
  // order
}

bool
qtw_interfaces__srv__ChangeArmMode_Request__are_equal(const qtw_interfaces__srv__ChangeArmMode_Request * lhs, const qtw_interfaces__srv__ChangeArmMode_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // order
  if (lhs->order != rhs->order) {
    return false;
  }
  return true;
}

bool
qtw_interfaces__srv__ChangeArmMode_Request__copy(
  const qtw_interfaces__srv__ChangeArmMode_Request * input,
  qtw_interfaces__srv__ChangeArmMode_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // order
  output->order = input->order;
  return true;
}

qtw_interfaces__srv__ChangeArmMode_Request *
qtw_interfaces__srv__ChangeArmMode_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  qtw_interfaces__srv__ChangeArmMode_Request * msg = (qtw_interfaces__srv__ChangeArmMode_Request *)allocator.allocate(sizeof(qtw_interfaces__srv__ChangeArmMode_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(qtw_interfaces__srv__ChangeArmMode_Request));
  bool success = qtw_interfaces__srv__ChangeArmMode_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
qtw_interfaces__srv__ChangeArmMode_Request__destroy(qtw_interfaces__srv__ChangeArmMode_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    qtw_interfaces__srv__ChangeArmMode_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
qtw_interfaces__srv__ChangeArmMode_Request__Sequence__init(qtw_interfaces__srv__ChangeArmMode_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  qtw_interfaces__srv__ChangeArmMode_Request * data = NULL;

  if (size) {
    data = (qtw_interfaces__srv__ChangeArmMode_Request *)allocator.zero_allocate(size, sizeof(qtw_interfaces__srv__ChangeArmMode_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = qtw_interfaces__srv__ChangeArmMode_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        qtw_interfaces__srv__ChangeArmMode_Request__fini(&data[i - 1]);
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
qtw_interfaces__srv__ChangeArmMode_Request__Sequence__fini(qtw_interfaces__srv__ChangeArmMode_Request__Sequence * array)
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
      qtw_interfaces__srv__ChangeArmMode_Request__fini(&array->data[i]);
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

qtw_interfaces__srv__ChangeArmMode_Request__Sequence *
qtw_interfaces__srv__ChangeArmMode_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  qtw_interfaces__srv__ChangeArmMode_Request__Sequence * array = (qtw_interfaces__srv__ChangeArmMode_Request__Sequence *)allocator.allocate(sizeof(qtw_interfaces__srv__ChangeArmMode_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = qtw_interfaces__srv__ChangeArmMode_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
qtw_interfaces__srv__ChangeArmMode_Request__Sequence__destroy(qtw_interfaces__srv__ChangeArmMode_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    qtw_interfaces__srv__ChangeArmMode_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
qtw_interfaces__srv__ChangeArmMode_Request__Sequence__are_equal(const qtw_interfaces__srv__ChangeArmMode_Request__Sequence * lhs, const qtw_interfaces__srv__ChangeArmMode_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!qtw_interfaces__srv__ChangeArmMode_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
qtw_interfaces__srv__ChangeArmMode_Request__Sequence__copy(
  const qtw_interfaces__srv__ChangeArmMode_Request__Sequence * input,
  qtw_interfaces__srv__ChangeArmMode_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(qtw_interfaces__srv__ChangeArmMode_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    qtw_interfaces__srv__ChangeArmMode_Request * data =
      (qtw_interfaces__srv__ChangeArmMode_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!qtw_interfaces__srv__ChangeArmMode_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          qtw_interfaces__srv__ChangeArmMode_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!qtw_interfaces__srv__ChangeArmMode_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


bool
qtw_interfaces__srv__ChangeArmMode_Response__init(qtw_interfaces__srv__ChangeArmMode_Response * msg)
{
  if (!msg) {
    return false;
  }
  // feedback
  return true;
}

void
qtw_interfaces__srv__ChangeArmMode_Response__fini(qtw_interfaces__srv__ChangeArmMode_Response * msg)
{
  if (!msg) {
    return;
  }
  // feedback
}

bool
qtw_interfaces__srv__ChangeArmMode_Response__are_equal(const qtw_interfaces__srv__ChangeArmMode_Response * lhs, const qtw_interfaces__srv__ChangeArmMode_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // feedback
  if (lhs->feedback != rhs->feedback) {
    return false;
  }
  return true;
}

bool
qtw_interfaces__srv__ChangeArmMode_Response__copy(
  const qtw_interfaces__srv__ChangeArmMode_Response * input,
  qtw_interfaces__srv__ChangeArmMode_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // feedback
  output->feedback = input->feedback;
  return true;
}

qtw_interfaces__srv__ChangeArmMode_Response *
qtw_interfaces__srv__ChangeArmMode_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  qtw_interfaces__srv__ChangeArmMode_Response * msg = (qtw_interfaces__srv__ChangeArmMode_Response *)allocator.allocate(sizeof(qtw_interfaces__srv__ChangeArmMode_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(qtw_interfaces__srv__ChangeArmMode_Response));
  bool success = qtw_interfaces__srv__ChangeArmMode_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
qtw_interfaces__srv__ChangeArmMode_Response__destroy(qtw_interfaces__srv__ChangeArmMode_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    qtw_interfaces__srv__ChangeArmMode_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
qtw_interfaces__srv__ChangeArmMode_Response__Sequence__init(qtw_interfaces__srv__ChangeArmMode_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  qtw_interfaces__srv__ChangeArmMode_Response * data = NULL;

  if (size) {
    data = (qtw_interfaces__srv__ChangeArmMode_Response *)allocator.zero_allocate(size, sizeof(qtw_interfaces__srv__ChangeArmMode_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = qtw_interfaces__srv__ChangeArmMode_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        qtw_interfaces__srv__ChangeArmMode_Response__fini(&data[i - 1]);
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
qtw_interfaces__srv__ChangeArmMode_Response__Sequence__fini(qtw_interfaces__srv__ChangeArmMode_Response__Sequence * array)
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
      qtw_interfaces__srv__ChangeArmMode_Response__fini(&array->data[i]);
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

qtw_interfaces__srv__ChangeArmMode_Response__Sequence *
qtw_interfaces__srv__ChangeArmMode_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  qtw_interfaces__srv__ChangeArmMode_Response__Sequence * array = (qtw_interfaces__srv__ChangeArmMode_Response__Sequence *)allocator.allocate(sizeof(qtw_interfaces__srv__ChangeArmMode_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = qtw_interfaces__srv__ChangeArmMode_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
qtw_interfaces__srv__ChangeArmMode_Response__Sequence__destroy(qtw_interfaces__srv__ChangeArmMode_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    qtw_interfaces__srv__ChangeArmMode_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
qtw_interfaces__srv__ChangeArmMode_Response__Sequence__are_equal(const qtw_interfaces__srv__ChangeArmMode_Response__Sequence * lhs, const qtw_interfaces__srv__ChangeArmMode_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!qtw_interfaces__srv__ChangeArmMode_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
qtw_interfaces__srv__ChangeArmMode_Response__Sequence__copy(
  const qtw_interfaces__srv__ChangeArmMode_Response__Sequence * input,
  qtw_interfaces__srv__ChangeArmMode_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(qtw_interfaces__srv__ChangeArmMode_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    qtw_interfaces__srv__ChangeArmMode_Response * data =
      (qtw_interfaces__srv__ChangeArmMode_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!qtw_interfaces__srv__ChangeArmMode_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          qtw_interfaces__srv__ChangeArmMode_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!qtw_interfaces__srv__ChangeArmMode_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
