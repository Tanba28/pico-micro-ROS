// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from qtw_interfaces:msg/Barometer.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "qtw_interfaces/msg/detail/barometer__rosidl_typesupport_introspection_c.h"
#include "qtw_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "qtw_interfaces/msg/detail/barometer__functions.h"
#include "qtw_interfaces/msg/detail/barometer__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void qtw_interfaces__msg__Barometer__rosidl_typesupport_introspection_c__Barometer_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  qtw_interfaces__msg__Barometer__init(message_memory);
}

void qtw_interfaces__msg__Barometer__rosidl_typesupport_introspection_c__Barometer_fini_function(void * message_memory)
{
  qtw_interfaces__msg__Barometer__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember qtw_interfaces__msg__Barometer__rosidl_typesupport_introspection_c__Barometer_message_member_array[3] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(qtw_interfaces__msg__Barometer, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "pressure",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(qtw_interfaces__msg__Barometer, pressure),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "temperature",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(qtw_interfaces__msg__Barometer, temperature),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers qtw_interfaces__msg__Barometer__rosidl_typesupport_introspection_c__Barometer_message_members = {
  "qtw_interfaces__msg",  // message namespace
  "Barometer",  // message name
  3,  // number of fields
  sizeof(qtw_interfaces__msg__Barometer),
  qtw_interfaces__msg__Barometer__rosidl_typesupport_introspection_c__Barometer_message_member_array,  // message members
  qtw_interfaces__msg__Barometer__rosidl_typesupport_introspection_c__Barometer_init_function,  // function to initialize message memory (memory has to be allocated)
  qtw_interfaces__msg__Barometer__rosidl_typesupport_introspection_c__Barometer_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t qtw_interfaces__msg__Barometer__rosidl_typesupport_introspection_c__Barometer_message_type_support_handle = {
  0,
  &qtw_interfaces__msg__Barometer__rosidl_typesupport_introspection_c__Barometer_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_qtw_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, qtw_interfaces, msg, Barometer)() {
  qtw_interfaces__msg__Barometer__rosidl_typesupport_introspection_c__Barometer_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  if (!qtw_interfaces__msg__Barometer__rosidl_typesupport_introspection_c__Barometer_message_type_support_handle.typesupport_identifier) {
    qtw_interfaces__msg__Barometer__rosidl_typesupport_introspection_c__Barometer_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &qtw_interfaces__msg__Barometer__rosidl_typesupport_introspection_c__Barometer_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif