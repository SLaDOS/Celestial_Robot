// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from celeste_interfaces:action/Return.idl
// generated code does not contain a copyright notice
#include "celeste_interfaces/action/detail/return__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `target`
#include "geometry_msgs/msg/detail/point__functions.h"

bool
celeste_interfaces__action__Return_Goal__init(celeste_interfaces__action__Return_Goal * msg)
{
  if (!msg) {
    return false;
  }
  // target
  if (!geometry_msgs__msg__Point__init(&msg->target)) {
    celeste_interfaces__action__Return_Goal__fini(msg);
    return false;
  }
  return true;
}

void
celeste_interfaces__action__Return_Goal__fini(celeste_interfaces__action__Return_Goal * msg)
{
  if (!msg) {
    return;
  }
  // target
  geometry_msgs__msg__Point__fini(&msg->target);
}

bool
celeste_interfaces__action__Return_Goal__are_equal(const celeste_interfaces__action__Return_Goal * lhs, const celeste_interfaces__action__Return_Goal * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // target
  if (!geometry_msgs__msg__Point__are_equal(
      &(lhs->target), &(rhs->target)))
  {
    return false;
  }
  return true;
}

bool
celeste_interfaces__action__Return_Goal__copy(
  const celeste_interfaces__action__Return_Goal * input,
  celeste_interfaces__action__Return_Goal * output)
{
  if (!input || !output) {
    return false;
  }
  // target
  if (!geometry_msgs__msg__Point__copy(
      &(input->target), &(output->target)))
  {
    return false;
  }
  return true;
}

celeste_interfaces__action__Return_Goal *
celeste_interfaces__action__Return_Goal__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  celeste_interfaces__action__Return_Goal * msg = (celeste_interfaces__action__Return_Goal *)allocator.allocate(sizeof(celeste_interfaces__action__Return_Goal), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(celeste_interfaces__action__Return_Goal));
  bool success = celeste_interfaces__action__Return_Goal__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
celeste_interfaces__action__Return_Goal__destroy(celeste_interfaces__action__Return_Goal * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    celeste_interfaces__action__Return_Goal__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
celeste_interfaces__action__Return_Goal__Sequence__init(celeste_interfaces__action__Return_Goal__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  celeste_interfaces__action__Return_Goal * data = NULL;

  if (size) {
    data = (celeste_interfaces__action__Return_Goal *)allocator.zero_allocate(size, sizeof(celeste_interfaces__action__Return_Goal), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = celeste_interfaces__action__Return_Goal__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        celeste_interfaces__action__Return_Goal__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
celeste_interfaces__action__Return_Goal__Sequence__fini(celeste_interfaces__action__Return_Goal__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      celeste_interfaces__action__Return_Goal__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

celeste_interfaces__action__Return_Goal__Sequence *
celeste_interfaces__action__Return_Goal__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  celeste_interfaces__action__Return_Goal__Sequence * array = (celeste_interfaces__action__Return_Goal__Sequence *)allocator.allocate(sizeof(celeste_interfaces__action__Return_Goal__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = celeste_interfaces__action__Return_Goal__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
celeste_interfaces__action__Return_Goal__Sequence__destroy(celeste_interfaces__action__Return_Goal__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    celeste_interfaces__action__Return_Goal__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
celeste_interfaces__action__Return_Goal__Sequence__are_equal(const celeste_interfaces__action__Return_Goal__Sequence * lhs, const celeste_interfaces__action__Return_Goal__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!celeste_interfaces__action__Return_Goal__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
celeste_interfaces__action__Return_Goal__Sequence__copy(
  const celeste_interfaces__action__Return_Goal__Sequence * input,
  celeste_interfaces__action__Return_Goal__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(celeste_interfaces__action__Return_Goal);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    celeste_interfaces__action__Return_Goal * data =
      (celeste_interfaces__action__Return_Goal *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!celeste_interfaces__action__Return_Goal__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          celeste_interfaces__action__Return_Goal__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!celeste_interfaces__action__Return_Goal__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


bool
celeste_interfaces__action__Return_Result__init(celeste_interfaces__action__Return_Result * msg)
{
  if (!msg) {
    return false;
  }
  // success
  return true;
}

void
celeste_interfaces__action__Return_Result__fini(celeste_interfaces__action__Return_Result * msg)
{
  if (!msg) {
    return;
  }
  // success
}

bool
celeste_interfaces__action__Return_Result__are_equal(const celeste_interfaces__action__Return_Result * lhs, const celeste_interfaces__action__Return_Result * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // success
  if (lhs->success != rhs->success) {
    return false;
  }
  return true;
}

bool
celeste_interfaces__action__Return_Result__copy(
  const celeste_interfaces__action__Return_Result * input,
  celeste_interfaces__action__Return_Result * output)
{
  if (!input || !output) {
    return false;
  }
  // success
  output->success = input->success;
  return true;
}

celeste_interfaces__action__Return_Result *
celeste_interfaces__action__Return_Result__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  celeste_interfaces__action__Return_Result * msg = (celeste_interfaces__action__Return_Result *)allocator.allocate(sizeof(celeste_interfaces__action__Return_Result), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(celeste_interfaces__action__Return_Result));
  bool success = celeste_interfaces__action__Return_Result__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
celeste_interfaces__action__Return_Result__destroy(celeste_interfaces__action__Return_Result * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    celeste_interfaces__action__Return_Result__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
celeste_interfaces__action__Return_Result__Sequence__init(celeste_interfaces__action__Return_Result__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  celeste_interfaces__action__Return_Result * data = NULL;

  if (size) {
    data = (celeste_interfaces__action__Return_Result *)allocator.zero_allocate(size, sizeof(celeste_interfaces__action__Return_Result), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = celeste_interfaces__action__Return_Result__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        celeste_interfaces__action__Return_Result__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
celeste_interfaces__action__Return_Result__Sequence__fini(celeste_interfaces__action__Return_Result__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      celeste_interfaces__action__Return_Result__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

celeste_interfaces__action__Return_Result__Sequence *
celeste_interfaces__action__Return_Result__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  celeste_interfaces__action__Return_Result__Sequence * array = (celeste_interfaces__action__Return_Result__Sequence *)allocator.allocate(sizeof(celeste_interfaces__action__Return_Result__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = celeste_interfaces__action__Return_Result__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
celeste_interfaces__action__Return_Result__Sequence__destroy(celeste_interfaces__action__Return_Result__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    celeste_interfaces__action__Return_Result__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
celeste_interfaces__action__Return_Result__Sequence__are_equal(const celeste_interfaces__action__Return_Result__Sequence * lhs, const celeste_interfaces__action__Return_Result__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!celeste_interfaces__action__Return_Result__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
celeste_interfaces__action__Return_Result__Sequence__copy(
  const celeste_interfaces__action__Return_Result__Sequence * input,
  celeste_interfaces__action__Return_Result__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(celeste_interfaces__action__Return_Result);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    celeste_interfaces__action__Return_Result * data =
      (celeste_interfaces__action__Return_Result *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!celeste_interfaces__action__Return_Result__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          celeste_interfaces__action__Return_Result__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!celeste_interfaces__action__Return_Result__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


bool
celeste_interfaces__action__Return_Feedback__init(celeste_interfaces__action__Return_Feedback * msg)
{
  if (!msg) {
    return false;
  }
  // distance_remaining
  return true;
}

void
celeste_interfaces__action__Return_Feedback__fini(celeste_interfaces__action__Return_Feedback * msg)
{
  if (!msg) {
    return;
  }
  // distance_remaining
}

bool
celeste_interfaces__action__Return_Feedback__are_equal(const celeste_interfaces__action__Return_Feedback * lhs, const celeste_interfaces__action__Return_Feedback * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // distance_remaining
  if (lhs->distance_remaining != rhs->distance_remaining) {
    return false;
  }
  return true;
}

bool
celeste_interfaces__action__Return_Feedback__copy(
  const celeste_interfaces__action__Return_Feedback * input,
  celeste_interfaces__action__Return_Feedback * output)
{
  if (!input || !output) {
    return false;
  }
  // distance_remaining
  output->distance_remaining = input->distance_remaining;
  return true;
}

celeste_interfaces__action__Return_Feedback *
celeste_interfaces__action__Return_Feedback__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  celeste_interfaces__action__Return_Feedback * msg = (celeste_interfaces__action__Return_Feedback *)allocator.allocate(sizeof(celeste_interfaces__action__Return_Feedback), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(celeste_interfaces__action__Return_Feedback));
  bool success = celeste_interfaces__action__Return_Feedback__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
celeste_interfaces__action__Return_Feedback__destroy(celeste_interfaces__action__Return_Feedback * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    celeste_interfaces__action__Return_Feedback__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
celeste_interfaces__action__Return_Feedback__Sequence__init(celeste_interfaces__action__Return_Feedback__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  celeste_interfaces__action__Return_Feedback * data = NULL;

  if (size) {
    data = (celeste_interfaces__action__Return_Feedback *)allocator.zero_allocate(size, sizeof(celeste_interfaces__action__Return_Feedback), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = celeste_interfaces__action__Return_Feedback__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        celeste_interfaces__action__Return_Feedback__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
celeste_interfaces__action__Return_Feedback__Sequence__fini(celeste_interfaces__action__Return_Feedback__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      celeste_interfaces__action__Return_Feedback__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

celeste_interfaces__action__Return_Feedback__Sequence *
celeste_interfaces__action__Return_Feedback__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  celeste_interfaces__action__Return_Feedback__Sequence * array = (celeste_interfaces__action__Return_Feedback__Sequence *)allocator.allocate(sizeof(celeste_interfaces__action__Return_Feedback__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = celeste_interfaces__action__Return_Feedback__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
celeste_interfaces__action__Return_Feedback__Sequence__destroy(celeste_interfaces__action__Return_Feedback__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    celeste_interfaces__action__Return_Feedback__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
celeste_interfaces__action__Return_Feedback__Sequence__are_equal(const celeste_interfaces__action__Return_Feedback__Sequence * lhs, const celeste_interfaces__action__Return_Feedback__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!celeste_interfaces__action__Return_Feedback__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
celeste_interfaces__action__Return_Feedback__Sequence__copy(
  const celeste_interfaces__action__Return_Feedback__Sequence * input,
  celeste_interfaces__action__Return_Feedback__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(celeste_interfaces__action__Return_Feedback);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    celeste_interfaces__action__Return_Feedback * data =
      (celeste_interfaces__action__Return_Feedback *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!celeste_interfaces__action__Return_Feedback__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          celeste_interfaces__action__Return_Feedback__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!celeste_interfaces__action__Return_Feedback__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
#include "unique_identifier_msgs/msg/detail/uuid__functions.h"
// Member `goal`
// already included above
// #include "celeste_interfaces/action/detail/return__functions.h"

bool
celeste_interfaces__action__Return_SendGoal_Request__init(celeste_interfaces__action__Return_SendGoal_Request * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    celeste_interfaces__action__Return_SendGoal_Request__fini(msg);
    return false;
  }
  // goal
  if (!celeste_interfaces__action__Return_Goal__init(&msg->goal)) {
    celeste_interfaces__action__Return_SendGoal_Request__fini(msg);
    return false;
  }
  return true;
}

void
celeste_interfaces__action__Return_SendGoal_Request__fini(celeste_interfaces__action__Return_SendGoal_Request * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
  // goal
  celeste_interfaces__action__Return_Goal__fini(&msg->goal);
}

bool
celeste_interfaces__action__Return_SendGoal_Request__are_equal(const celeste_interfaces__action__Return_SendGoal_Request * lhs, const celeste_interfaces__action__Return_SendGoal_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  // goal
  if (!celeste_interfaces__action__Return_Goal__are_equal(
      &(lhs->goal), &(rhs->goal)))
  {
    return false;
  }
  return true;
}

bool
celeste_interfaces__action__Return_SendGoal_Request__copy(
  const celeste_interfaces__action__Return_SendGoal_Request * input,
  celeste_interfaces__action__Return_SendGoal_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  // goal
  if (!celeste_interfaces__action__Return_Goal__copy(
      &(input->goal), &(output->goal)))
  {
    return false;
  }
  return true;
}

celeste_interfaces__action__Return_SendGoal_Request *
celeste_interfaces__action__Return_SendGoal_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  celeste_interfaces__action__Return_SendGoal_Request * msg = (celeste_interfaces__action__Return_SendGoal_Request *)allocator.allocate(sizeof(celeste_interfaces__action__Return_SendGoal_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(celeste_interfaces__action__Return_SendGoal_Request));
  bool success = celeste_interfaces__action__Return_SendGoal_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
celeste_interfaces__action__Return_SendGoal_Request__destroy(celeste_interfaces__action__Return_SendGoal_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    celeste_interfaces__action__Return_SendGoal_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
celeste_interfaces__action__Return_SendGoal_Request__Sequence__init(celeste_interfaces__action__Return_SendGoal_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  celeste_interfaces__action__Return_SendGoal_Request * data = NULL;

  if (size) {
    data = (celeste_interfaces__action__Return_SendGoal_Request *)allocator.zero_allocate(size, sizeof(celeste_interfaces__action__Return_SendGoal_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = celeste_interfaces__action__Return_SendGoal_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        celeste_interfaces__action__Return_SendGoal_Request__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
celeste_interfaces__action__Return_SendGoal_Request__Sequence__fini(celeste_interfaces__action__Return_SendGoal_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      celeste_interfaces__action__Return_SendGoal_Request__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

celeste_interfaces__action__Return_SendGoal_Request__Sequence *
celeste_interfaces__action__Return_SendGoal_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  celeste_interfaces__action__Return_SendGoal_Request__Sequence * array = (celeste_interfaces__action__Return_SendGoal_Request__Sequence *)allocator.allocate(sizeof(celeste_interfaces__action__Return_SendGoal_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = celeste_interfaces__action__Return_SendGoal_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
celeste_interfaces__action__Return_SendGoal_Request__Sequence__destroy(celeste_interfaces__action__Return_SendGoal_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    celeste_interfaces__action__Return_SendGoal_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
celeste_interfaces__action__Return_SendGoal_Request__Sequence__are_equal(const celeste_interfaces__action__Return_SendGoal_Request__Sequence * lhs, const celeste_interfaces__action__Return_SendGoal_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!celeste_interfaces__action__Return_SendGoal_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
celeste_interfaces__action__Return_SendGoal_Request__Sequence__copy(
  const celeste_interfaces__action__Return_SendGoal_Request__Sequence * input,
  celeste_interfaces__action__Return_SendGoal_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(celeste_interfaces__action__Return_SendGoal_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    celeste_interfaces__action__Return_SendGoal_Request * data =
      (celeste_interfaces__action__Return_SendGoal_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!celeste_interfaces__action__Return_SendGoal_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          celeste_interfaces__action__Return_SendGoal_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!celeste_interfaces__action__Return_SendGoal_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `stamp`
#include "builtin_interfaces/msg/detail/time__functions.h"

bool
celeste_interfaces__action__Return_SendGoal_Response__init(celeste_interfaces__action__Return_SendGoal_Response * msg)
{
  if (!msg) {
    return false;
  }
  // accepted
  // stamp
  if (!builtin_interfaces__msg__Time__init(&msg->stamp)) {
    celeste_interfaces__action__Return_SendGoal_Response__fini(msg);
    return false;
  }
  return true;
}

void
celeste_interfaces__action__Return_SendGoal_Response__fini(celeste_interfaces__action__Return_SendGoal_Response * msg)
{
  if (!msg) {
    return;
  }
  // accepted
  // stamp
  builtin_interfaces__msg__Time__fini(&msg->stamp);
}

bool
celeste_interfaces__action__Return_SendGoal_Response__are_equal(const celeste_interfaces__action__Return_SendGoal_Response * lhs, const celeste_interfaces__action__Return_SendGoal_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // accepted
  if (lhs->accepted != rhs->accepted) {
    return false;
  }
  // stamp
  if (!builtin_interfaces__msg__Time__are_equal(
      &(lhs->stamp), &(rhs->stamp)))
  {
    return false;
  }
  return true;
}

bool
celeste_interfaces__action__Return_SendGoal_Response__copy(
  const celeste_interfaces__action__Return_SendGoal_Response * input,
  celeste_interfaces__action__Return_SendGoal_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // accepted
  output->accepted = input->accepted;
  // stamp
  if (!builtin_interfaces__msg__Time__copy(
      &(input->stamp), &(output->stamp)))
  {
    return false;
  }
  return true;
}

celeste_interfaces__action__Return_SendGoal_Response *
celeste_interfaces__action__Return_SendGoal_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  celeste_interfaces__action__Return_SendGoal_Response * msg = (celeste_interfaces__action__Return_SendGoal_Response *)allocator.allocate(sizeof(celeste_interfaces__action__Return_SendGoal_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(celeste_interfaces__action__Return_SendGoal_Response));
  bool success = celeste_interfaces__action__Return_SendGoal_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
celeste_interfaces__action__Return_SendGoal_Response__destroy(celeste_interfaces__action__Return_SendGoal_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    celeste_interfaces__action__Return_SendGoal_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
celeste_interfaces__action__Return_SendGoal_Response__Sequence__init(celeste_interfaces__action__Return_SendGoal_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  celeste_interfaces__action__Return_SendGoal_Response * data = NULL;

  if (size) {
    data = (celeste_interfaces__action__Return_SendGoal_Response *)allocator.zero_allocate(size, sizeof(celeste_interfaces__action__Return_SendGoal_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = celeste_interfaces__action__Return_SendGoal_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        celeste_interfaces__action__Return_SendGoal_Response__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
celeste_interfaces__action__Return_SendGoal_Response__Sequence__fini(celeste_interfaces__action__Return_SendGoal_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      celeste_interfaces__action__Return_SendGoal_Response__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

celeste_interfaces__action__Return_SendGoal_Response__Sequence *
celeste_interfaces__action__Return_SendGoal_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  celeste_interfaces__action__Return_SendGoal_Response__Sequence * array = (celeste_interfaces__action__Return_SendGoal_Response__Sequence *)allocator.allocate(sizeof(celeste_interfaces__action__Return_SendGoal_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = celeste_interfaces__action__Return_SendGoal_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
celeste_interfaces__action__Return_SendGoal_Response__Sequence__destroy(celeste_interfaces__action__Return_SendGoal_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    celeste_interfaces__action__Return_SendGoal_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
celeste_interfaces__action__Return_SendGoal_Response__Sequence__are_equal(const celeste_interfaces__action__Return_SendGoal_Response__Sequence * lhs, const celeste_interfaces__action__Return_SendGoal_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!celeste_interfaces__action__Return_SendGoal_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
celeste_interfaces__action__Return_SendGoal_Response__Sequence__copy(
  const celeste_interfaces__action__Return_SendGoal_Response__Sequence * input,
  celeste_interfaces__action__Return_SendGoal_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(celeste_interfaces__action__Return_SendGoal_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    celeste_interfaces__action__Return_SendGoal_Response * data =
      (celeste_interfaces__action__Return_SendGoal_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!celeste_interfaces__action__Return_SendGoal_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          celeste_interfaces__action__Return_SendGoal_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!celeste_interfaces__action__Return_SendGoal_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__functions.h"

bool
celeste_interfaces__action__Return_GetResult_Request__init(celeste_interfaces__action__Return_GetResult_Request * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    celeste_interfaces__action__Return_GetResult_Request__fini(msg);
    return false;
  }
  return true;
}

void
celeste_interfaces__action__Return_GetResult_Request__fini(celeste_interfaces__action__Return_GetResult_Request * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
}

bool
celeste_interfaces__action__Return_GetResult_Request__are_equal(const celeste_interfaces__action__Return_GetResult_Request * lhs, const celeste_interfaces__action__Return_GetResult_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  return true;
}

bool
celeste_interfaces__action__Return_GetResult_Request__copy(
  const celeste_interfaces__action__Return_GetResult_Request * input,
  celeste_interfaces__action__Return_GetResult_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  return true;
}

celeste_interfaces__action__Return_GetResult_Request *
celeste_interfaces__action__Return_GetResult_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  celeste_interfaces__action__Return_GetResult_Request * msg = (celeste_interfaces__action__Return_GetResult_Request *)allocator.allocate(sizeof(celeste_interfaces__action__Return_GetResult_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(celeste_interfaces__action__Return_GetResult_Request));
  bool success = celeste_interfaces__action__Return_GetResult_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
celeste_interfaces__action__Return_GetResult_Request__destroy(celeste_interfaces__action__Return_GetResult_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    celeste_interfaces__action__Return_GetResult_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
celeste_interfaces__action__Return_GetResult_Request__Sequence__init(celeste_interfaces__action__Return_GetResult_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  celeste_interfaces__action__Return_GetResult_Request * data = NULL;

  if (size) {
    data = (celeste_interfaces__action__Return_GetResult_Request *)allocator.zero_allocate(size, sizeof(celeste_interfaces__action__Return_GetResult_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = celeste_interfaces__action__Return_GetResult_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        celeste_interfaces__action__Return_GetResult_Request__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
celeste_interfaces__action__Return_GetResult_Request__Sequence__fini(celeste_interfaces__action__Return_GetResult_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      celeste_interfaces__action__Return_GetResult_Request__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

celeste_interfaces__action__Return_GetResult_Request__Sequence *
celeste_interfaces__action__Return_GetResult_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  celeste_interfaces__action__Return_GetResult_Request__Sequence * array = (celeste_interfaces__action__Return_GetResult_Request__Sequence *)allocator.allocate(sizeof(celeste_interfaces__action__Return_GetResult_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = celeste_interfaces__action__Return_GetResult_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
celeste_interfaces__action__Return_GetResult_Request__Sequence__destroy(celeste_interfaces__action__Return_GetResult_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    celeste_interfaces__action__Return_GetResult_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
celeste_interfaces__action__Return_GetResult_Request__Sequence__are_equal(const celeste_interfaces__action__Return_GetResult_Request__Sequence * lhs, const celeste_interfaces__action__Return_GetResult_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!celeste_interfaces__action__Return_GetResult_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
celeste_interfaces__action__Return_GetResult_Request__Sequence__copy(
  const celeste_interfaces__action__Return_GetResult_Request__Sequence * input,
  celeste_interfaces__action__Return_GetResult_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(celeste_interfaces__action__Return_GetResult_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    celeste_interfaces__action__Return_GetResult_Request * data =
      (celeste_interfaces__action__Return_GetResult_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!celeste_interfaces__action__Return_GetResult_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          celeste_interfaces__action__Return_GetResult_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!celeste_interfaces__action__Return_GetResult_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `result`
// already included above
// #include "celeste_interfaces/action/detail/return__functions.h"

bool
celeste_interfaces__action__Return_GetResult_Response__init(celeste_interfaces__action__Return_GetResult_Response * msg)
{
  if (!msg) {
    return false;
  }
  // status
  // result
  if (!celeste_interfaces__action__Return_Result__init(&msg->result)) {
    celeste_interfaces__action__Return_GetResult_Response__fini(msg);
    return false;
  }
  return true;
}

void
celeste_interfaces__action__Return_GetResult_Response__fini(celeste_interfaces__action__Return_GetResult_Response * msg)
{
  if (!msg) {
    return;
  }
  // status
  // result
  celeste_interfaces__action__Return_Result__fini(&msg->result);
}

bool
celeste_interfaces__action__Return_GetResult_Response__are_equal(const celeste_interfaces__action__Return_GetResult_Response * lhs, const celeste_interfaces__action__Return_GetResult_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // status
  if (lhs->status != rhs->status) {
    return false;
  }
  // result
  if (!celeste_interfaces__action__Return_Result__are_equal(
      &(lhs->result), &(rhs->result)))
  {
    return false;
  }
  return true;
}

bool
celeste_interfaces__action__Return_GetResult_Response__copy(
  const celeste_interfaces__action__Return_GetResult_Response * input,
  celeste_interfaces__action__Return_GetResult_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // status
  output->status = input->status;
  // result
  if (!celeste_interfaces__action__Return_Result__copy(
      &(input->result), &(output->result)))
  {
    return false;
  }
  return true;
}

celeste_interfaces__action__Return_GetResult_Response *
celeste_interfaces__action__Return_GetResult_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  celeste_interfaces__action__Return_GetResult_Response * msg = (celeste_interfaces__action__Return_GetResult_Response *)allocator.allocate(sizeof(celeste_interfaces__action__Return_GetResult_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(celeste_interfaces__action__Return_GetResult_Response));
  bool success = celeste_interfaces__action__Return_GetResult_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
celeste_interfaces__action__Return_GetResult_Response__destroy(celeste_interfaces__action__Return_GetResult_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    celeste_interfaces__action__Return_GetResult_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
celeste_interfaces__action__Return_GetResult_Response__Sequence__init(celeste_interfaces__action__Return_GetResult_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  celeste_interfaces__action__Return_GetResult_Response * data = NULL;

  if (size) {
    data = (celeste_interfaces__action__Return_GetResult_Response *)allocator.zero_allocate(size, sizeof(celeste_interfaces__action__Return_GetResult_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = celeste_interfaces__action__Return_GetResult_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        celeste_interfaces__action__Return_GetResult_Response__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
celeste_interfaces__action__Return_GetResult_Response__Sequence__fini(celeste_interfaces__action__Return_GetResult_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      celeste_interfaces__action__Return_GetResult_Response__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

celeste_interfaces__action__Return_GetResult_Response__Sequence *
celeste_interfaces__action__Return_GetResult_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  celeste_interfaces__action__Return_GetResult_Response__Sequence * array = (celeste_interfaces__action__Return_GetResult_Response__Sequence *)allocator.allocate(sizeof(celeste_interfaces__action__Return_GetResult_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = celeste_interfaces__action__Return_GetResult_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
celeste_interfaces__action__Return_GetResult_Response__Sequence__destroy(celeste_interfaces__action__Return_GetResult_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    celeste_interfaces__action__Return_GetResult_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
celeste_interfaces__action__Return_GetResult_Response__Sequence__are_equal(const celeste_interfaces__action__Return_GetResult_Response__Sequence * lhs, const celeste_interfaces__action__Return_GetResult_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!celeste_interfaces__action__Return_GetResult_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
celeste_interfaces__action__Return_GetResult_Response__Sequence__copy(
  const celeste_interfaces__action__Return_GetResult_Response__Sequence * input,
  celeste_interfaces__action__Return_GetResult_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(celeste_interfaces__action__Return_GetResult_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    celeste_interfaces__action__Return_GetResult_Response * data =
      (celeste_interfaces__action__Return_GetResult_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!celeste_interfaces__action__Return_GetResult_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          celeste_interfaces__action__Return_GetResult_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!celeste_interfaces__action__Return_GetResult_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__functions.h"
// Member `feedback`
// already included above
// #include "celeste_interfaces/action/detail/return__functions.h"

bool
celeste_interfaces__action__Return_FeedbackMessage__init(celeste_interfaces__action__Return_FeedbackMessage * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    celeste_interfaces__action__Return_FeedbackMessage__fini(msg);
    return false;
  }
  // feedback
  if (!celeste_interfaces__action__Return_Feedback__init(&msg->feedback)) {
    celeste_interfaces__action__Return_FeedbackMessage__fini(msg);
    return false;
  }
  return true;
}

void
celeste_interfaces__action__Return_FeedbackMessage__fini(celeste_interfaces__action__Return_FeedbackMessage * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
  // feedback
  celeste_interfaces__action__Return_Feedback__fini(&msg->feedback);
}

bool
celeste_interfaces__action__Return_FeedbackMessage__are_equal(const celeste_interfaces__action__Return_FeedbackMessage * lhs, const celeste_interfaces__action__Return_FeedbackMessage * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  // feedback
  if (!celeste_interfaces__action__Return_Feedback__are_equal(
      &(lhs->feedback), &(rhs->feedback)))
  {
    return false;
  }
  return true;
}

bool
celeste_interfaces__action__Return_FeedbackMessage__copy(
  const celeste_interfaces__action__Return_FeedbackMessage * input,
  celeste_interfaces__action__Return_FeedbackMessage * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  // feedback
  if (!celeste_interfaces__action__Return_Feedback__copy(
      &(input->feedback), &(output->feedback)))
  {
    return false;
  }
  return true;
}

celeste_interfaces__action__Return_FeedbackMessage *
celeste_interfaces__action__Return_FeedbackMessage__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  celeste_interfaces__action__Return_FeedbackMessage * msg = (celeste_interfaces__action__Return_FeedbackMessage *)allocator.allocate(sizeof(celeste_interfaces__action__Return_FeedbackMessage), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(celeste_interfaces__action__Return_FeedbackMessage));
  bool success = celeste_interfaces__action__Return_FeedbackMessage__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
celeste_interfaces__action__Return_FeedbackMessage__destroy(celeste_interfaces__action__Return_FeedbackMessage * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    celeste_interfaces__action__Return_FeedbackMessage__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
celeste_interfaces__action__Return_FeedbackMessage__Sequence__init(celeste_interfaces__action__Return_FeedbackMessage__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  celeste_interfaces__action__Return_FeedbackMessage * data = NULL;

  if (size) {
    data = (celeste_interfaces__action__Return_FeedbackMessage *)allocator.zero_allocate(size, sizeof(celeste_interfaces__action__Return_FeedbackMessage), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = celeste_interfaces__action__Return_FeedbackMessage__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        celeste_interfaces__action__Return_FeedbackMessage__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
celeste_interfaces__action__Return_FeedbackMessage__Sequence__fini(celeste_interfaces__action__Return_FeedbackMessage__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      celeste_interfaces__action__Return_FeedbackMessage__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

celeste_interfaces__action__Return_FeedbackMessage__Sequence *
celeste_interfaces__action__Return_FeedbackMessage__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  celeste_interfaces__action__Return_FeedbackMessage__Sequence * array = (celeste_interfaces__action__Return_FeedbackMessage__Sequence *)allocator.allocate(sizeof(celeste_interfaces__action__Return_FeedbackMessage__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = celeste_interfaces__action__Return_FeedbackMessage__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
celeste_interfaces__action__Return_FeedbackMessage__Sequence__destroy(celeste_interfaces__action__Return_FeedbackMessage__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    celeste_interfaces__action__Return_FeedbackMessage__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
celeste_interfaces__action__Return_FeedbackMessage__Sequence__are_equal(const celeste_interfaces__action__Return_FeedbackMessage__Sequence * lhs, const celeste_interfaces__action__Return_FeedbackMessage__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!celeste_interfaces__action__Return_FeedbackMessage__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
celeste_interfaces__action__Return_FeedbackMessage__Sequence__copy(
  const celeste_interfaces__action__Return_FeedbackMessage__Sequence * input,
  celeste_interfaces__action__Return_FeedbackMessage__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(celeste_interfaces__action__Return_FeedbackMessage);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    celeste_interfaces__action__Return_FeedbackMessage * data =
      (celeste_interfaces__action__Return_FeedbackMessage *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!celeste_interfaces__action__Return_FeedbackMessage__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          celeste_interfaces__action__Return_FeedbackMessage__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!celeste_interfaces__action__Return_FeedbackMessage__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
