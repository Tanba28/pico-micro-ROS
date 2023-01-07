// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from qtw_interfaces:msg/Status.idl
// generated code does not contain a copyright notice

#ifndef QTW_INTERFACES__MSG__DETAIL__STATUS__STRUCT_H_
#define QTW_INTERFACES__MSG__DETAIL__STATUS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/Status in the package qtw_interfaces.
typedef struct qtw_interfaces__msg__Status
{
  uint8_t module_id;
  uint8_t status;
  float voltage;
} qtw_interfaces__msg__Status;

// Struct for a sequence of qtw_interfaces__msg__Status.
typedef struct qtw_interfaces__msg__Status__Sequence
{
  qtw_interfaces__msg__Status * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} qtw_interfaces__msg__Status__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // QTW_INTERFACES__MSG__DETAIL__STATUS__STRUCT_H_
