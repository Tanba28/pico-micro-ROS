// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from qtw_interfaces:msg/Estimate.idl
// generated code does not contain a copyright notice

#ifndef QTW_INTERFACES__MSG__DETAIL__ESTIMATE__STRUCT_H_
#define QTW_INTERFACES__MSG__DETAIL__ESTIMATE__STRUCT_H_

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
// Member 'pose'
#include "geometry_msgs/msg/detail/pose__struct.h"
// Member 'twist'
#include "geometry_msgs/msg/detail/twist__struct.h"

/// Struct defined in msg/Estimate in the package qtw_interfaces.
typedef struct qtw_interfaces__msg__Estimate
{
  builtin_interfaces__msg__Time stamp;
  geometry_msgs__msg__Pose pose;
  geometry_msgs__msg__Twist twist;
} qtw_interfaces__msg__Estimate;

// Struct for a sequence of qtw_interfaces__msg__Estimate.
typedef struct qtw_interfaces__msg__Estimate__Sequence
{
  qtw_interfaces__msg__Estimate * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} qtw_interfaces__msg__Estimate__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // QTW_INTERFACES__MSG__DETAIL__ESTIMATE__STRUCT_H_
