// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from qtw_interfaces:msg/Estimate.idl
// generated code does not contain a copyright notice

#ifndef QTW_INTERFACES__MSG__DETAIL__ESTIMATE__FUNCTIONS_H_
#define QTW_INTERFACES__MSG__DETAIL__ESTIMATE__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "qtw_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "qtw_interfaces/msg/detail/estimate__struct.h"

/// Initialize msg/Estimate message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * qtw_interfaces__msg__Estimate
 * )) before or use
 * qtw_interfaces__msg__Estimate__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_qtw_interfaces
bool
qtw_interfaces__msg__Estimate__init(qtw_interfaces__msg__Estimate * msg);

/// Finalize msg/Estimate message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_qtw_interfaces
void
qtw_interfaces__msg__Estimate__fini(qtw_interfaces__msg__Estimate * msg);

/// Create msg/Estimate message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * qtw_interfaces__msg__Estimate__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_qtw_interfaces
qtw_interfaces__msg__Estimate *
qtw_interfaces__msg__Estimate__create();

/// Destroy msg/Estimate message.
/**
 * It calls
 * qtw_interfaces__msg__Estimate__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_qtw_interfaces
void
qtw_interfaces__msg__Estimate__destroy(qtw_interfaces__msg__Estimate * msg);

/// Check for msg/Estimate message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_qtw_interfaces
bool
qtw_interfaces__msg__Estimate__are_equal(const qtw_interfaces__msg__Estimate * lhs, const qtw_interfaces__msg__Estimate * rhs);

/// Copy a msg/Estimate message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_qtw_interfaces
bool
qtw_interfaces__msg__Estimate__copy(
  const qtw_interfaces__msg__Estimate * input,
  qtw_interfaces__msg__Estimate * output);

/// Initialize array of msg/Estimate messages.
/**
 * It allocates the memory for the number of elements and calls
 * qtw_interfaces__msg__Estimate__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_qtw_interfaces
bool
qtw_interfaces__msg__Estimate__Sequence__init(qtw_interfaces__msg__Estimate__Sequence * array, size_t size);

/// Finalize array of msg/Estimate messages.
/**
 * It calls
 * qtw_interfaces__msg__Estimate__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_qtw_interfaces
void
qtw_interfaces__msg__Estimate__Sequence__fini(qtw_interfaces__msg__Estimate__Sequence * array);

/// Create array of msg/Estimate messages.
/**
 * It allocates the memory for the array and calls
 * qtw_interfaces__msg__Estimate__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_qtw_interfaces
qtw_interfaces__msg__Estimate__Sequence *
qtw_interfaces__msg__Estimate__Sequence__create(size_t size);

/// Destroy array of msg/Estimate messages.
/**
 * It calls
 * qtw_interfaces__msg__Estimate__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_qtw_interfaces
void
qtw_interfaces__msg__Estimate__Sequence__destroy(qtw_interfaces__msg__Estimate__Sequence * array);

/// Check for msg/Estimate message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_qtw_interfaces
bool
qtw_interfaces__msg__Estimate__Sequence__are_equal(const qtw_interfaces__msg__Estimate__Sequence * lhs, const qtw_interfaces__msg__Estimate__Sequence * rhs);

/// Copy an array of msg/Estimate messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_qtw_interfaces
bool
qtw_interfaces__msg__Estimate__Sequence__copy(
  const qtw_interfaces__msg__Estimate__Sequence * input,
  qtw_interfaces__msg__Estimate__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // QTW_INTERFACES__MSG__DETAIL__ESTIMATE__FUNCTIONS_H_
