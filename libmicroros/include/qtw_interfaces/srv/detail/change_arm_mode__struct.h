// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from qtw_interfaces:srv/ChangeArmMode.idl
// generated code does not contain a copyright notice

#ifndef QTW_INTERFACES__SRV__DETAIL__CHANGE_ARM_MODE__STRUCT_H_
#define QTW_INTERFACES__SRV__DETAIL__CHANGE_ARM_MODE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/ChangeArmMode in the package qtw_interfaces.
typedef struct qtw_interfaces__srv__ChangeArmMode_Request
{
  bool order;
} qtw_interfaces__srv__ChangeArmMode_Request;

// Struct for a sequence of qtw_interfaces__srv__ChangeArmMode_Request.
typedef struct qtw_interfaces__srv__ChangeArmMode_Request__Sequence
{
  qtw_interfaces__srv__ChangeArmMode_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} qtw_interfaces__srv__ChangeArmMode_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/ChangeArmMode in the package qtw_interfaces.
typedef struct qtw_interfaces__srv__ChangeArmMode_Response
{
  bool feedback;
} qtw_interfaces__srv__ChangeArmMode_Response;

// Struct for a sequence of qtw_interfaces__srv__ChangeArmMode_Response.
typedef struct qtw_interfaces__srv__ChangeArmMode_Response__Sequence
{
  qtw_interfaces__srv__ChangeArmMode_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} qtw_interfaces__srv__ChangeArmMode_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // QTW_INTERFACES__SRV__DETAIL__CHANGE_ARM_MODE__STRUCT_H_
