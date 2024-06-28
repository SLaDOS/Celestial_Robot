// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from celeste_interfaces:action/Return.idl
// generated code does not contain a copyright notice

#ifndef CELESTE_INTERFACES__ACTION__DETAIL__RETURN__FUNCTIONS_H_
#define CELESTE_INTERFACES__ACTION__DETAIL__RETURN__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "celeste_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "celeste_interfaces/action/detail/return__struct.h"

/// Initialize action/Return message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * celeste_interfaces__action__Return_Goal
 * )) before or use
 * celeste_interfaces__action__Return_Goal__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_celeste_interfaces
bool
celeste_interfaces__action__Return_Goal__init(celeste_interfaces__action__Return_Goal * msg);

/// Finalize action/Return message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_celeste_interfaces
void
celeste_interfaces__action__Return_Goal__fini(celeste_interfaces__action__Return_Goal * msg);

/// Create action/Return message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * celeste_interfaces__action__Return_Goal__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_celeste_interfaces
celeste_interfaces__action__Return_Goal *
celeste_interfaces__action__Return_Goal__create();

/// Destroy action/Return message.
/**
 * It calls
 * celeste_interfaces__action__Return_Goal__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_celeste_interfaces
void
celeste_interfaces__action__Return_Goal__destroy(celeste_interfaces__action__Return_Goal * msg);

/// Check for action/Return message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_celeste_interfaces
bool
celeste_interfaces__action__Return_Goal__are_equal(const celeste_interfaces__action__Return_Goal * lhs, const celeste_interfaces__action__Return_Goal * rhs);

/// Copy a action/Return message.
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
ROSIDL_GENERATOR_C_PUBLIC_celeste_interfaces
bool
celeste_interfaces__action__Return_Goal__copy(
  const celeste_interfaces__action__Return_Goal * input,
  celeste_interfaces__action__Return_Goal * output);

/// Initialize array of action/Return messages.
/**
 * It allocates the memory for the number of elements and calls
 * celeste_interfaces__action__Return_Goal__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_celeste_interfaces
bool
celeste_interfaces__action__Return_Goal__Sequence__init(celeste_interfaces__action__Return_Goal__Sequence * array, size_t size);

/// Finalize array of action/Return messages.
/**
 * It calls
 * celeste_interfaces__action__Return_Goal__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_celeste_interfaces
void
celeste_interfaces__action__Return_Goal__Sequence__fini(celeste_interfaces__action__Return_Goal__Sequence * array);

/// Create array of action/Return messages.
/**
 * It allocates the memory for the array and calls
 * celeste_interfaces__action__Return_Goal__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_celeste_interfaces
celeste_interfaces__action__Return_Goal__Sequence *
celeste_interfaces__action__Return_Goal__Sequence__create(size_t size);

/// Destroy array of action/Return messages.
/**
 * It calls
 * celeste_interfaces__action__Return_Goal__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_celeste_interfaces
void
celeste_interfaces__action__Return_Goal__Sequence__destroy(celeste_interfaces__action__Return_Goal__Sequence * array);

/// Check for action/Return message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_celeste_interfaces
bool
celeste_interfaces__action__Return_Goal__Sequence__are_equal(const celeste_interfaces__action__Return_Goal__Sequence * lhs, const celeste_interfaces__action__Return_Goal__Sequence * rhs);

/// Copy an array of action/Return messages.
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
ROSIDL_GENERATOR_C_PUBLIC_celeste_interfaces
bool
celeste_interfaces__action__Return_Goal__Sequence__copy(
  const celeste_interfaces__action__Return_Goal__Sequence * input,
  celeste_interfaces__action__Return_Goal__Sequence * output);

/// Initialize action/Return message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * celeste_interfaces__action__Return_Result
 * )) before or use
 * celeste_interfaces__action__Return_Result__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_celeste_interfaces
bool
celeste_interfaces__action__Return_Result__init(celeste_interfaces__action__Return_Result * msg);

/// Finalize action/Return message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_celeste_interfaces
void
celeste_interfaces__action__Return_Result__fini(celeste_interfaces__action__Return_Result * msg);

/// Create action/Return message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * celeste_interfaces__action__Return_Result__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_celeste_interfaces
celeste_interfaces__action__Return_Result *
celeste_interfaces__action__Return_Result__create();

/// Destroy action/Return message.
/**
 * It calls
 * celeste_interfaces__action__Return_Result__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_celeste_interfaces
void
celeste_interfaces__action__Return_Result__destroy(celeste_interfaces__action__Return_Result * msg);

/// Check for action/Return message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_celeste_interfaces
bool
celeste_interfaces__action__Return_Result__are_equal(const celeste_interfaces__action__Return_Result * lhs, const celeste_interfaces__action__Return_Result * rhs);

/// Copy a action/Return message.
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
ROSIDL_GENERATOR_C_PUBLIC_celeste_interfaces
bool
celeste_interfaces__action__Return_Result__copy(
  const celeste_interfaces__action__Return_Result * input,
  celeste_interfaces__action__Return_Result * output);

/// Initialize array of action/Return messages.
/**
 * It allocates the memory for the number of elements and calls
 * celeste_interfaces__action__Return_Result__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_celeste_interfaces
bool
celeste_interfaces__action__Return_Result__Sequence__init(celeste_interfaces__action__Return_Result__Sequence * array, size_t size);

/// Finalize array of action/Return messages.
/**
 * It calls
 * celeste_interfaces__action__Return_Result__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_celeste_interfaces
void
celeste_interfaces__action__Return_Result__Sequence__fini(celeste_interfaces__action__Return_Result__Sequence * array);

/// Create array of action/Return messages.
/**
 * It allocates the memory for the array and calls
 * celeste_interfaces__action__Return_Result__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_celeste_interfaces
celeste_interfaces__action__Return_Result__Sequence *
celeste_interfaces__action__Return_Result__Sequence__create(size_t size);

/// Destroy array of action/Return messages.
/**
 * It calls
 * celeste_interfaces__action__Return_Result__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_celeste_interfaces
void
celeste_interfaces__action__Return_Result__Sequence__destroy(celeste_interfaces__action__Return_Result__Sequence * array);

/// Check for action/Return message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_celeste_interfaces
bool
celeste_interfaces__action__Return_Result__Sequence__are_equal(const celeste_interfaces__action__Return_Result__Sequence * lhs, const celeste_interfaces__action__Return_Result__Sequence * rhs);

/// Copy an array of action/Return messages.
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
ROSIDL_GENERATOR_C_PUBLIC_celeste_interfaces
bool
celeste_interfaces__action__Return_Result__Sequence__copy(
  const celeste_interfaces__action__Return_Result__Sequence * input,
  celeste_interfaces__action__Return_Result__Sequence * output);

/// Initialize action/Return message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * celeste_interfaces__action__Return_Feedback
 * )) before or use
 * celeste_interfaces__action__Return_Feedback__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_celeste_interfaces
bool
celeste_interfaces__action__Return_Feedback__init(celeste_interfaces__action__Return_Feedback * msg);

/// Finalize action/Return message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_celeste_interfaces
void
celeste_interfaces__action__Return_Feedback__fini(celeste_interfaces__action__Return_Feedback * msg);

/// Create action/Return message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * celeste_interfaces__action__Return_Feedback__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_celeste_interfaces
celeste_interfaces__action__Return_Feedback *
celeste_interfaces__action__Return_Feedback__create();

/// Destroy action/Return message.
/**
 * It calls
 * celeste_interfaces__action__Return_Feedback__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_celeste_interfaces
void
celeste_interfaces__action__Return_Feedback__destroy(celeste_interfaces__action__Return_Feedback * msg);

/// Check for action/Return message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_celeste_interfaces
bool
celeste_interfaces__action__Return_Feedback__are_equal(const celeste_interfaces__action__Return_Feedback * lhs, const celeste_interfaces__action__Return_Feedback * rhs);

/// Copy a action/Return message.
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
ROSIDL_GENERATOR_C_PUBLIC_celeste_interfaces
bool
celeste_interfaces__action__Return_Feedback__copy(
  const celeste_interfaces__action__Return_Feedback * input,
  celeste_interfaces__action__Return_Feedback * output);

/// Initialize array of action/Return messages.
/**
 * It allocates the memory for the number of elements and calls
 * celeste_interfaces__action__Return_Feedback__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_celeste_interfaces
bool
celeste_interfaces__action__Return_Feedback__Sequence__init(celeste_interfaces__action__Return_Feedback__Sequence * array, size_t size);

/// Finalize array of action/Return messages.
/**
 * It calls
 * celeste_interfaces__action__Return_Feedback__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_celeste_interfaces
void
celeste_interfaces__action__Return_Feedback__Sequence__fini(celeste_interfaces__action__Return_Feedback__Sequence * array);

/// Create array of action/Return messages.
/**
 * It allocates the memory for the array and calls
 * celeste_interfaces__action__Return_Feedback__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_celeste_interfaces
celeste_interfaces__action__Return_Feedback__Sequence *
celeste_interfaces__action__Return_Feedback__Sequence__create(size_t size);

/// Destroy array of action/Return messages.
/**
 * It calls
 * celeste_interfaces__action__Return_Feedback__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_celeste_interfaces
void
celeste_interfaces__action__Return_Feedback__Sequence__destroy(celeste_interfaces__action__Return_Feedback__Sequence * array);

/// Check for action/Return message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_celeste_interfaces
bool
celeste_interfaces__action__Return_Feedback__Sequence__are_equal(const celeste_interfaces__action__Return_Feedback__Sequence * lhs, const celeste_interfaces__action__Return_Feedback__Sequence * rhs);

/// Copy an array of action/Return messages.
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
ROSIDL_GENERATOR_C_PUBLIC_celeste_interfaces
bool
celeste_interfaces__action__Return_Feedback__Sequence__copy(
  const celeste_interfaces__action__Return_Feedback__Sequence * input,
  celeste_interfaces__action__Return_Feedback__Sequence * output);

/// Initialize action/Return message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * celeste_interfaces__action__Return_SendGoal_Request
 * )) before or use
 * celeste_interfaces__action__Return_SendGoal_Request__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_celeste_interfaces
bool
celeste_interfaces__action__Return_SendGoal_Request__init(celeste_interfaces__action__Return_SendGoal_Request * msg);

/// Finalize action/Return message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_celeste_interfaces
void
celeste_interfaces__action__Return_SendGoal_Request__fini(celeste_interfaces__action__Return_SendGoal_Request * msg);

/// Create action/Return message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * celeste_interfaces__action__Return_SendGoal_Request__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_celeste_interfaces
celeste_interfaces__action__Return_SendGoal_Request *
celeste_interfaces__action__Return_SendGoal_Request__create();

/// Destroy action/Return message.
/**
 * It calls
 * celeste_interfaces__action__Return_SendGoal_Request__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_celeste_interfaces
void
celeste_interfaces__action__Return_SendGoal_Request__destroy(celeste_interfaces__action__Return_SendGoal_Request * msg);

/// Check for action/Return message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_celeste_interfaces
bool
celeste_interfaces__action__Return_SendGoal_Request__are_equal(const celeste_interfaces__action__Return_SendGoal_Request * lhs, const celeste_interfaces__action__Return_SendGoal_Request * rhs);

/// Copy a action/Return message.
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
ROSIDL_GENERATOR_C_PUBLIC_celeste_interfaces
bool
celeste_interfaces__action__Return_SendGoal_Request__copy(
  const celeste_interfaces__action__Return_SendGoal_Request * input,
  celeste_interfaces__action__Return_SendGoal_Request * output);

/// Initialize array of action/Return messages.
/**
 * It allocates the memory for the number of elements and calls
 * celeste_interfaces__action__Return_SendGoal_Request__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_celeste_interfaces
bool
celeste_interfaces__action__Return_SendGoal_Request__Sequence__init(celeste_interfaces__action__Return_SendGoal_Request__Sequence * array, size_t size);

/// Finalize array of action/Return messages.
/**
 * It calls
 * celeste_interfaces__action__Return_SendGoal_Request__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_celeste_interfaces
void
celeste_interfaces__action__Return_SendGoal_Request__Sequence__fini(celeste_interfaces__action__Return_SendGoal_Request__Sequence * array);

/// Create array of action/Return messages.
/**
 * It allocates the memory for the array and calls
 * celeste_interfaces__action__Return_SendGoal_Request__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_celeste_interfaces
celeste_interfaces__action__Return_SendGoal_Request__Sequence *
celeste_interfaces__action__Return_SendGoal_Request__Sequence__create(size_t size);

/// Destroy array of action/Return messages.
/**
 * It calls
 * celeste_interfaces__action__Return_SendGoal_Request__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_celeste_interfaces
void
celeste_interfaces__action__Return_SendGoal_Request__Sequence__destroy(celeste_interfaces__action__Return_SendGoal_Request__Sequence * array);

/// Check for action/Return message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_celeste_interfaces
bool
celeste_interfaces__action__Return_SendGoal_Request__Sequence__are_equal(const celeste_interfaces__action__Return_SendGoal_Request__Sequence * lhs, const celeste_interfaces__action__Return_SendGoal_Request__Sequence * rhs);

/// Copy an array of action/Return messages.
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
ROSIDL_GENERATOR_C_PUBLIC_celeste_interfaces
bool
celeste_interfaces__action__Return_SendGoal_Request__Sequence__copy(
  const celeste_interfaces__action__Return_SendGoal_Request__Sequence * input,
  celeste_interfaces__action__Return_SendGoal_Request__Sequence * output);

/// Initialize action/Return message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * celeste_interfaces__action__Return_SendGoal_Response
 * )) before or use
 * celeste_interfaces__action__Return_SendGoal_Response__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_celeste_interfaces
bool
celeste_interfaces__action__Return_SendGoal_Response__init(celeste_interfaces__action__Return_SendGoal_Response * msg);

/// Finalize action/Return message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_celeste_interfaces
void
celeste_interfaces__action__Return_SendGoal_Response__fini(celeste_interfaces__action__Return_SendGoal_Response * msg);

/// Create action/Return message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * celeste_interfaces__action__Return_SendGoal_Response__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_celeste_interfaces
celeste_interfaces__action__Return_SendGoal_Response *
celeste_interfaces__action__Return_SendGoal_Response__create();

/// Destroy action/Return message.
/**
 * It calls
 * celeste_interfaces__action__Return_SendGoal_Response__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_celeste_interfaces
void
celeste_interfaces__action__Return_SendGoal_Response__destroy(celeste_interfaces__action__Return_SendGoal_Response * msg);

/// Check for action/Return message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_celeste_interfaces
bool
celeste_interfaces__action__Return_SendGoal_Response__are_equal(const celeste_interfaces__action__Return_SendGoal_Response * lhs, const celeste_interfaces__action__Return_SendGoal_Response * rhs);

/// Copy a action/Return message.
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
ROSIDL_GENERATOR_C_PUBLIC_celeste_interfaces
bool
celeste_interfaces__action__Return_SendGoal_Response__copy(
  const celeste_interfaces__action__Return_SendGoal_Response * input,
  celeste_interfaces__action__Return_SendGoal_Response * output);

/// Initialize array of action/Return messages.
/**
 * It allocates the memory for the number of elements and calls
 * celeste_interfaces__action__Return_SendGoal_Response__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_celeste_interfaces
bool
celeste_interfaces__action__Return_SendGoal_Response__Sequence__init(celeste_interfaces__action__Return_SendGoal_Response__Sequence * array, size_t size);

/// Finalize array of action/Return messages.
/**
 * It calls
 * celeste_interfaces__action__Return_SendGoal_Response__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_celeste_interfaces
void
celeste_interfaces__action__Return_SendGoal_Response__Sequence__fini(celeste_interfaces__action__Return_SendGoal_Response__Sequence * array);

/// Create array of action/Return messages.
/**
 * It allocates the memory for the array and calls
 * celeste_interfaces__action__Return_SendGoal_Response__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_celeste_interfaces
celeste_interfaces__action__Return_SendGoal_Response__Sequence *
celeste_interfaces__action__Return_SendGoal_Response__Sequence__create(size_t size);

/// Destroy array of action/Return messages.
/**
 * It calls
 * celeste_interfaces__action__Return_SendGoal_Response__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_celeste_interfaces
void
celeste_interfaces__action__Return_SendGoal_Response__Sequence__destroy(celeste_interfaces__action__Return_SendGoal_Response__Sequence * array);

/// Check for action/Return message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_celeste_interfaces
bool
celeste_interfaces__action__Return_SendGoal_Response__Sequence__are_equal(const celeste_interfaces__action__Return_SendGoal_Response__Sequence * lhs, const celeste_interfaces__action__Return_SendGoal_Response__Sequence * rhs);

/// Copy an array of action/Return messages.
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
ROSIDL_GENERATOR_C_PUBLIC_celeste_interfaces
bool
celeste_interfaces__action__Return_SendGoal_Response__Sequence__copy(
  const celeste_interfaces__action__Return_SendGoal_Response__Sequence * input,
  celeste_interfaces__action__Return_SendGoal_Response__Sequence * output);

/// Initialize action/Return message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * celeste_interfaces__action__Return_GetResult_Request
 * )) before or use
 * celeste_interfaces__action__Return_GetResult_Request__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_celeste_interfaces
bool
celeste_interfaces__action__Return_GetResult_Request__init(celeste_interfaces__action__Return_GetResult_Request * msg);

/// Finalize action/Return message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_celeste_interfaces
void
celeste_interfaces__action__Return_GetResult_Request__fini(celeste_interfaces__action__Return_GetResult_Request * msg);

/// Create action/Return message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * celeste_interfaces__action__Return_GetResult_Request__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_celeste_interfaces
celeste_interfaces__action__Return_GetResult_Request *
celeste_interfaces__action__Return_GetResult_Request__create();

/// Destroy action/Return message.
/**
 * It calls
 * celeste_interfaces__action__Return_GetResult_Request__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_celeste_interfaces
void
celeste_interfaces__action__Return_GetResult_Request__destroy(celeste_interfaces__action__Return_GetResult_Request * msg);

/// Check for action/Return message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_celeste_interfaces
bool
celeste_interfaces__action__Return_GetResult_Request__are_equal(const celeste_interfaces__action__Return_GetResult_Request * lhs, const celeste_interfaces__action__Return_GetResult_Request * rhs);

/// Copy a action/Return message.
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
ROSIDL_GENERATOR_C_PUBLIC_celeste_interfaces
bool
celeste_interfaces__action__Return_GetResult_Request__copy(
  const celeste_interfaces__action__Return_GetResult_Request * input,
  celeste_interfaces__action__Return_GetResult_Request * output);

/// Initialize array of action/Return messages.
/**
 * It allocates the memory for the number of elements and calls
 * celeste_interfaces__action__Return_GetResult_Request__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_celeste_interfaces
bool
celeste_interfaces__action__Return_GetResult_Request__Sequence__init(celeste_interfaces__action__Return_GetResult_Request__Sequence * array, size_t size);

/// Finalize array of action/Return messages.
/**
 * It calls
 * celeste_interfaces__action__Return_GetResult_Request__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_celeste_interfaces
void
celeste_interfaces__action__Return_GetResult_Request__Sequence__fini(celeste_interfaces__action__Return_GetResult_Request__Sequence * array);

/// Create array of action/Return messages.
/**
 * It allocates the memory for the array and calls
 * celeste_interfaces__action__Return_GetResult_Request__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_celeste_interfaces
celeste_interfaces__action__Return_GetResult_Request__Sequence *
celeste_interfaces__action__Return_GetResult_Request__Sequence__create(size_t size);

/// Destroy array of action/Return messages.
/**
 * It calls
 * celeste_interfaces__action__Return_GetResult_Request__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_celeste_interfaces
void
celeste_interfaces__action__Return_GetResult_Request__Sequence__destroy(celeste_interfaces__action__Return_GetResult_Request__Sequence * array);

/// Check for action/Return message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_celeste_interfaces
bool
celeste_interfaces__action__Return_GetResult_Request__Sequence__are_equal(const celeste_interfaces__action__Return_GetResult_Request__Sequence * lhs, const celeste_interfaces__action__Return_GetResult_Request__Sequence * rhs);

/// Copy an array of action/Return messages.
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
ROSIDL_GENERATOR_C_PUBLIC_celeste_interfaces
bool
celeste_interfaces__action__Return_GetResult_Request__Sequence__copy(
  const celeste_interfaces__action__Return_GetResult_Request__Sequence * input,
  celeste_interfaces__action__Return_GetResult_Request__Sequence * output);

/// Initialize action/Return message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * celeste_interfaces__action__Return_GetResult_Response
 * )) before or use
 * celeste_interfaces__action__Return_GetResult_Response__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_celeste_interfaces
bool
celeste_interfaces__action__Return_GetResult_Response__init(celeste_interfaces__action__Return_GetResult_Response * msg);

/// Finalize action/Return message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_celeste_interfaces
void
celeste_interfaces__action__Return_GetResult_Response__fini(celeste_interfaces__action__Return_GetResult_Response * msg);

/// Create action/Return message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * celeste_interfaces__action__Return_GetResult_Response__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_celeste_interfaces
celeste_interfaces__action__Return_GetResult_Response *
celeste_interfaces__action__Return_GetResult_Response__create();

/// Destroy action/Return message.
/**
 * It calls
 * celeste_interfaces__action__Return_GetResult_Response__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_celeste_interfaces
void
celeste_interfaces__action__Return_GetResult_Response__destroy(celeste_interfaces__action__Return_GetResult_Response * msg);

/// Check for action/Return message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_celeste_interfaces
bool
celeste_interfaces__action__Return_GetResult_Response__are_equal(const celeste_interfaces__action__Return_GetResult_Response * lhs, const celeste_interfaces__action__Return_GetResult_Response * rhs);

/// Copy a action/Return message.
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
ROSIDL_GENERATOR_C_PUBLIC_celeste_interfaces
bool
celeste_interfaces__action__Return_GetResult_Response__copy(
  const celeste_interfaces__action__Return_GetResult_Response * input,
  celeste_interfaces__action__Return_GetResult_Response * output);

/// Initialize array of action/Return messages.
/**
 * It allocates the memory for the number of elements and calls
 * celeste_interfaces__action__Return_GetResult_Response__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_celeste_interfaces
bool
celeste_interfaces__action__Return_GetResult_Response__Sequence__init(celeste_interfaces__action__Return_GetResult_Response__Sequence * array, size_t size);

/// Finalize array of action/Return messages.
/**
 * It calls
 * celeste_interfaces__action__Return_GetResult_Response__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_celeste_interfaces
void
celeste_interfaces__action__Return_GetResult_Response__Sequence__fini(celeste_interfaces__action__Return_GetResult_Response__Sequence * array);

/// Create array of action/Return messages.
/**
 * It allocates the memory for the array and calls
 * celeste_interfaces__action__Return_GetResult_Response__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_celeste_interfaces
celeste_interfaces__action__Return_GetResult_Response__Sequence *
celeste_interfaces__action__Return_GetResult_Response__Sequence__create(size_t size);

/// Destroy array of action/Return messages.
/**
 * It calls
 * celeste_interfaces__action__Return_GetResult_Response__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_celeste_interfaces
void
celeste_interfaces__action__Return_GetResult_Response__Sequence__destroy(celeste_interfaces__action__Return_GetResult_Response__Sequence * array);

/// Check for action/Return message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_celeste_interfaces
bool
celeste_interfaces__action__Return_GetResult_Response__Sequence__are_equal(const celeste_interfaces__action__Return_GetResult_Response__Sequence * lhs, const celeste_interfaces__action__Return_GetResult_Response__Sequence * rhs);

/// Copy an array of action/Return messages.
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
ROSIDL_GENERATOR_C_PUBLIC_celeste_interfaces
bool
celeste_interfaces__action__Return_GetResult_Response__Sequence__copy(
  const celeste_interfaces__action__Return_GetResult_Response__Sequence * input,
  celeste_interfaces__action__Return_GetResult_Response__Sequence * output);

/// Initialize action/Return message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * celeste_interfaces__action__Return_FeedbackMessage
 * )) before or use
 * celeste_interfaces__action__Return_FeedbackMessage__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_celeste_interfaces
bool
celeste_interfaces__action__Return_FeedbackMessage__init(celeste_interfaces__action__Return_FeedbackMessage * msg);

/// Finalize action/Return message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_celeste_interfaces
void
celeste_interfaces__action__Return_FeedbackMessage__fini(celeste_interfaces__action__Return_FeedbackMessage * msg);

/// Create action/Return message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * celeste_interfaces__action__Return_FeedbackMessage__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_celeste_interfaces
celeste_interfaces__action__Return_FeedbackMessage *
celeste_interfaces__action__Return_FeedbackMessage__create();

/// Destroy action/Return message.
/**
 * It calls
 * celeste_interfaces__action__Return_FeedbackMessage__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_celeste_interfaces
void
celeste_interfaces__action__Return_FeedbackMessage__destroy(celeste_interfaces__action__Return_FeedbackMessage * msg);

/// Check for action/Return message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_celeste_interfaces
bool
celeste_interfaces__action__Return_FeedbackMessage__are_equal(const celeste_interfaces__action__Return_FeedbackMessage * lhs, const celeste_interfaces__action__Return_FeedbackMessage * rhs);

/// Copy a action/Return message.
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
ROSIDL_GENERATOR_C_PUBLIC_celeste_interfaces
bool
celeste_interfaces__action__Return_FeedbackMessage__copy(
  const celeste_interfaces__action__Return_FeedbackMessage * input,
  celeste_interfaces__action__Return_FeedbackMessage * output);

/// Initialize array of action/Return messages.
/**
 * It allocates the memory for the number of elements and calls
 * celeste_interfaces__action__Return_FeedbackMessage__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_celeste_interfaces
bool
celeste_interfaces__action__Return_FeedbackMessage__Sequence__init(celeste_interfaces__action__Return_FeedbackMessage__Sequence * array, size_t size);

/// Finalize array of action/Return messages.
/**
 * It calls
 * celeste_interfaces__action__Return_FeedbackMessage__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_celeste_interfaces
void
celeste_interfaces__action__Return_FeedbackMessage__Sequence__fini(celeste_interfaces__action__Return_FeedbackMessage__Sequence * array);

/// Create array of action/Return messages.
/**
 * It allocates the memory for the array and calls
 * celeste_interfaces__action__Return_FeedbackMessage__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_celeste_interfaces
celeste_interfaces__action__Return_FeedbackMessage__Sequence *
celeste_interfaces__action__Return_FeedbackMessage__Sequence__create(size_t size);

/// Destroy array of action/Return messages.
/**
 * It calls
 * celeste_interfaces__action__Return_FeedbackMessage__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_celeste_interfaces
void
celeste_interfaces__action__Return_FeedbackMessage__Sequence__destroy(celeste_interfaces__action__Return_FeedbackMessage__Sequence * array);

/// Check for action/Return message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_celeste_interfaces
bool
celeste_interfaces__action__Return_FeedbackMessage__Sequence__are_equal(const celeste_interfaces__action__Return_FeedbackMessage__Sequence * lhs, const celeste_interfaces__action__Return_FeedbackMessage__Sequence * rhs);

/// Copy an array of action/Return messages.
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
ROSIDL_GENERATOR_C_PUBLIC_celeste_interfaces
bool
celeste_interfaces__action__Return_FeedbackMessage__Sequence__copy(
  const celeste_interfaces__action__Return_FeedbackMessage__Sequence * input,
  celeste_interfaces__action__Return_FeedbackMessage__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // CELESTE_INTERFACES__ACTION__DETAIL__RETURN__FUNCTIONS_H_
