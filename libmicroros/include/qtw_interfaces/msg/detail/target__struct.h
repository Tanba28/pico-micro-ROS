// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from qtw_interfaces:msg/Target.idl
// generated code does not contain a copyright notice

#ifndef QTW_INTERFACES__MSG__DETAIL__TARGET__STRUCT_H_
#define QTW_INTERFACES__MSG__DETAIL__TARGET__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.h"

/// Struct defined in msg/Target in the package qtw_interfaces.
typedef struct qtw_interfaces__msg__Target
{
  builtin_interfaces__msg__Time stamp;
  uint16_t value_1;
  uint16_t value_2;
  uint16_t value_3;
  uint16_t value_4;
  uint16_t value_5;
  uint16_t value_6;
  uint16_t value_7;
  uint16_t value_8;
} qtw_interfaces__msg__Target;

// Struct for a sequence of qtw_interfaces__msg__Target.
typedef struct qtw_interfaces__msg__Target__Sequence
{
  qtw_interfaces__msg__Target * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} qtw_interfaces__msg__Target__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // QTW_INTERFACES__MSG__DETAIL__TARGET__STRUCT_H_
