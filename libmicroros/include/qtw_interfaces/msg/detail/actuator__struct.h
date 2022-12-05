// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from qtw_interfaces:msg/Actuator.idl
// generated code does not contain a copyright notice

#ifndef QTW_INTERFACES__MSG__DETAIL__ACTUATOR__STRUCT_H_
#define QTW_INTERFACES__MSG__DETAIL__ACTUATOR__STRUCT_H_

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

/// Struct defined in msg/Actuator in the package qtw_interfaces.
typedef struct qtw_interfaces__msg__Actuator
{
  std_msgs__msg__Header header;
  /// deg
  float tilt_front;
  /// deg
  float tilt_back;
  /// deg
  float flap_front_right;
  /// deg
  float flap_front_left;
  /// deg
  float flap_back_right;
  /// deg
  float flap_back_left;
  /// deg
  float rudder;
  /// N
  float thrust_front_right;
  /// N
  float thrust_front_left;
  /// N
  float thrust_back_right;
  /// N
  float thrust_back_left;
} qtw_interfaces__msg__Actuator;

// Struct for a sequence of qtw_interfaces__msg__Actuator.
typedef struct qtw_interfaces__msg__Actuator__Sequence
{
  qtw_interfaces__msg__Actuator * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} qtw_interfaces__msg__Actuator__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // QTW_INTERFACES__MSG__DETAIL__ACTUATOR__STRUCT_H_
