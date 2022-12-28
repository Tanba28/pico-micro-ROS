// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from qtw_interfaces:msg/Sensor.idl
// generated code does not contain a copyright notice

#ifndef QTW_INTERFACES__MSG__DETAIL__SENSOR__STRUCT_H_
#define QTW_INTERFACES__MSG__DETAIL__SENSOR__STRUCT_H_

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
// Member 'accel'
// Member 'gyro'
// Member 'mag'
#include "geometry_msgs/msg/detail/vector3__struct.h"

/// Struct defined in msg/Sensor in the package qtw_interfaces.
typedef struct qtw_interfaces__msg__Sensor
{
  builtin_interfaces__msg__Time stamp;
  geometry_msgs__msg__Vector3 accel;
  geometry_msgs__msg__Vector3 gyro;
  geometry_msgs__msg__Vector3 mag;
  float pressure;
  float temperature;
  uint16_t front_tilt;
  uint16_t rear_tilt;
} qtw_interfaces__msg__Sensor;

// Struct for a sequence of qtw_interfaces__msg__Sensor.
typedef struct qtw_interfaces__msg__Sensor__Sequence
{
  qtw_interfaces__msg__Sensor * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} qtw_interfaces__msg__Sensor__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // QTW_INTERFACES__MSG__DETAIL__SENSOR__STRUCT_H_
