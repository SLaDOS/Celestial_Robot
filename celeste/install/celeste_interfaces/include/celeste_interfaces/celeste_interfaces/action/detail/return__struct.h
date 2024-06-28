// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from celeste_interfaces:action/Return.idl
// generated code does not contain a copyright notice

#ifndef CELESTE_INTERFACES__ACTION__DETAIL__RETURN__STRUCT_H_
#define CELESTE_INTERFACES__ACTION__DETAIL__RETURN__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'target'
#include "geometry_msgs/msg/detail/point__struct.h"

/// Struct defined in action/Return in the package celeste_interfaces.
typedef struct celeste_interfaces__action__Return_Goal
{
  geometry_msgs__msg__Point target;
} celeste_interfaces__action__Return_Goal;

// Struct for a sequence of celeste_interfaces__action__Return_Goal.
typedef struct celeste_interfaces__action__Return_Goal__Sequence
{
  celeste_interfaces__action__Return_Goal * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} celeste_interfaces__action__Return_Goal__Sequence;


// Constants defined in the message

/// Struct defined in action/Return in the package celeste_interfaces.
typedef struct celeste_interfaces__action__Return_Result
{
  bool success;
} celeste_interfaces__action__Return_Result;

// Struct for a sequence of celeste_interfaces__action__Return_Result.
typedef struct celeste_interfaces__action__Return_Result__Sequence
{
  celeste_interfaces__action__Return_Result * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} celeste_interfaces__action__Return_Result__Sequence;


// Constants defined in the message

/// Struct defined in action/Return in the package celeste_interfaces.
typedef struct celeste_interfaces__action__Return_Feedback
{
  float distance_remaining;
} celeste_interfaces__action__Return_Feedback;

// Struct for a sequence of celeste_interfaces__action__Return_Feedback.
typedef struct celeste_interfaces__action__Return_Feedback__Sequence
{
  celeste_interfaces__action__Return_Feedback * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} celeste_interfaces__action__Return_Feedback__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'goal'
#include "celeste_interfaces/action/detail/return__struct.h"

/// Struct defined in action/Return in the package celeste_interfaces.
typedef struct celeste_interfaces__action__Return_SendGoal_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
  celeste_interfaces__action__Return_Goal goal;
} celeste_interfaces__action__Return_SendGoal_Request;

// Struct for a sequence of celeste_interfaces__action__Return_SendGoal_Request.
typedef struct celeste_interfaces__action__Return_SendGoal_Request__Sequence
{
  celeste_interfaces__action__Return_SendGoal_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} celeste_interfaces__action__Return_SendGoal_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.h"

/// Struct defined in action/Return in the package celeste_interfaces.
typedef struct celeste_interfaces__action__Return_SendGoal_Response
{
  bool accepted;
  builtin_interfaces__msg__Time stamp;
} celeste_interfaces__action__Return_SendGoal_Response;

// Struct for a sequence of celeste_interfaces__action__Return_SendGoal_Response.
typedef struct celeste_interfaces__action__Return_SendGoal_Response__Sequence
{
  celeste_interfaces__action__Return_SendGoal_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} celeste_interfaces__action__Return_SendGoal_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"

/// Struct defined in action/Return in the package celeste_interfaces.
typedef struct celeste_interfaces__action__Return_GetResult_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
} celeste_interfaces__action__Return_GetResult_Request;

// Struct for a sequence of celeste_interfaces__action__Return_GetResult_Request.
typedef struct celeste_interfaces__action__Return_GetResult_Request__Sequence
{
  celeste_interfaces__action__Return_GetResult_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} celeste_interfaces__action__Return_GetResult_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'result'
// already included above
// #include "celeste_interfaces/action/detail/return__struct.h"

/// Struct defined in action/Return in the package celeste_interfaces.
typedef struct celeste_interfaces__action__Return_GetResult_Response
{
  int8_t status;
  celeste_interfaces__action__Return_Result result;
} celeste_interfaces__action__Return_GetResult_Response;

// Struct for a sequence of celeste_interfaces__action__Return_GetResult_Response.
typedef struct celeste_interfaces__action__Return_GetResult_Response__Sequence
{
  celeste_interfaces__action__Return_GetResult_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} celeste_interfaces__action__Return_GetResult_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'feedback'
// already included above
// #include "celeste_interfaces/action/detail/return__struct.h"

/// Struct defined in action/Return in the package celeste_interfaces.
typedef struct celeste_interfaces__action__Return_FeedbackMessage
{
  unique_identifier_msgs__msg__UUID goal_id;
  celeste_interfaces__action__Return_Feedback feedback;
} celeste_interfaces__action__Return_FeedbackMessage;

// Struct for a sequence of celeste_interfaces__action__Return_FeedbackMessage.
typedef struct celeste_interfaces__action__Return_FeedbackMessage__Sequence
{
  celeste_interfaces__action__Return_FeedbackMessage * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} celeste_interfaces__action__Return_FeedbackMessage__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CELESTE_INTERFACES__ACTION__DETAIL__RETURN__STRUCT_H_
