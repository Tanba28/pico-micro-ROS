// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from qtw_interfaces:msg/Barometer.idl
// generated code does not contain a copyright notice

#ifndef QTW_INTERFACES__MSG__DETAIL__BAROMETER__STRUCT_H_
#define QTW_INTERFACES__MSG__DETAIL__BAROMETER__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"

/// Struct defined in msg/Barometer in the package qtw_interfaces.
typedef struct qtw_interfaces__msg__Barometer
{
  std_msgs__msg__Header header;
  float pressure;
  float temperature;
} qtw_interfaces__msg__Barometer;

// Struct for a sequence of qtw_interfaces__msg__Barometer.
typedef struct qtw_interfaces__msg__Barometer__Sequence
{
  qtw_interfaces__msg__Barometer * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} qtw_interfaces__msg__Barometer__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // QTW_INTERFACES__MSG__DETAIL__BAROMETER__STRUCT_H_
