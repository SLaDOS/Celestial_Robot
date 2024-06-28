// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from celeste_interfaces:action/Return.idl
// generated code does not contain a copyright notice

#ifndef CELESTE_INTERFACES__ACTION__DETAIL__RETURN__BUILDER_HPP_
#define CELESTE_INTERFACES__ACTION__DETAIL__RETURN__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "celeste_interfaces/action/detail/return__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace celeste_interfaces
{

namespace action
{

namespace builder
{

class Init_Return_Goal_target
{
public:
  Init_Return_Goal_target()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::celeste_interfaces::action::Return_Goal target(::celeste_interfaces::action::Return_Goal::_target_type arg)
  {
    msg_.target = std::move(arg);
    return std::move(msg_);
  }

private:
  ::celeste_interfaces::action::Return_Goal msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::celeste_interfaces::action::Return_Goal>()
{
  return celeste_interfaces::action::builder::Init_Return_Goal_target();
}

}  // namespace celeste_interfaces


namespace celeste_interfaces
{

namespace action
{

namespace builder
{

class Init_Return_Result_success
{
public:
  Init_Return_Result_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::celeste_interfaces::action::Return_Result success(::celeste_interfaces::action::Return_Result::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::celeste_interfaces::action::Return_Result msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::celeste_interfaces::action::Return_Result>()
{
  return celeste_interfaces::action::builder::Init_Return_Result_success();
}

}  // namespace celeste_interfaces


namespace celeste_interfaces
{

namespace action
{

namespace builder
{

class Init_Return_Feedback_distance_remaining
{
public:
  Init_Return_Feedback_distance_remaining()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::celeste_interfaces::action::Return_Feedback distance_remaining(::celeste_interfaces::action::Return_Feedback::_distance_remaining_type arg)
  {
    msg_.distance_remaining = std::move(arg);
    return std::move(msg_);
  }

private:
  ::celeste_interfaces::action::Return_Feedback msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::celeste_interfaces::action::Return_Feedback>()
{
  return celeste_interfaces::action::builder::Init_Return_Feedback_distance_remaining();
}

}  // namespace celeste_interfaces


namespace celeste_interfaces
{

namespace action
{

namespace builder
{

class Init_Return_SendGoal_Request_goal
{
public:
  explicit Init_Return_SendGoal_Request_goal(::celeste_interfaces::action::Return_SendGoal_Request & msg)
  : msg_(msg)
  {}
  ::celeste_interfaces::action::Return_SendGoal_Request goal(::celeste_interfaces::action::Return_SendGoal_Request::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::celeste_interfaces::action::Return_SendGoal_Request msg_;
};

class Init_Return_SendGoal_Request_goal_id
{
public:
  Init_Return_SendGoal_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Return_SendGoal_Request_goal goal_id(::celeste_interfaces::action::Return_SendGoal_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_Return_SendGoal_Request_goal(msg_);
  }

private:
  ::celeste_interfaces::action::Return_SendGoal_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::celeste_interfaces::action::Return_SendGoal_Request>()
{
  return celeste_interfaces::action::builder::Init_Return_SendGoal_Request_goal_id();
}

}  // namespace celeste_interfaces


namespace celeste_interfaces
{

namespace action
{

namespace builder
{

class Init_Return_SendGoal_Response_stamp
{
public:
  explicit Init_Return_SendGoal_Response_stamp(::celeste_interfaces::action::Return_SendGoal_Response & msg)
  : msg_(msg)
  {}
  ::celeste_interfaces::action::Return_SendGoal_Response stamp(::celeste_interfaces::action::Return_SendGoal_Response::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::celeste_interfaces::action::Return_SendGoal_Response msg_;
};

class Init_Return_SendGoal_Response_accepted
{
public:
  Init_Return_SendGoal_Response_accepted()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Return_SendGoal_Response_stamp accepted(::celeste_interfaces::action::Return_SendGoal_Response::_accepted_type arg)
  {
    msg_.accepted = std::move(arg);
    return Init_Return_SendGoal_Response_stamp(msg_);
  }

private:
  ::celeste_interfaces::action::Return_SendGoal_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::celeste_interfaces::action::Return_SendGoal_Response>()
{
  return celeste_interfaces::action::builder::Init_Return_SendGoal_Response_accepted();
}

}  // namespace celeste_interfaces


namespace celeste_interfaces
{

namespace action
{

namespace builder
{

class Init_Return_GetResult_Request_goal_id
{
public:
  Init_Return_GetResult_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::celeste_interfaces::action::Return_GetResult_Request goal_id(::celeste_interfaces::action::Return_GetResult_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::celeste_interfaces::action::Return_GetResult_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::celeste_interfaces::action::Return_GetResult_Request>()
{
  return celeste_interfaces::action::builder::Init_Return_GetResult_Request_goal_id();
}

}  // namespace celeste_interfaces


namespace celeste_interfaces
{

namespace action
{

namespace builder
{

class Init_Return_GetResult_Response_result
{
public:
  explicit Init_Return_GetResult_Response_result(::celeste_interfaces::action::Return_GetResult_Response & msg)
  : msg_(msg)
  {}
  ::celeste_interfaces::action::Return_GetResult_Response result(::celeste_interfaces::action::Return_GetResult_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::celeste_interfaces::action::Return_GetResult_Response msg_;
};

class Init_Return_GetResult_Response_status
{
public:
  Init_Return_GetResult_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Return_GetResult_Response_result status(::celeste_interfaces::action::Return_GetResult_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_Return_GetResult_Response_result(msg_);
  }

private:
  ::celeste_interfaces::action::Return_GetResult_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::celeste_interfaces::action::Return_GetResult_Response>()
{
  return celeste_interfaces::action::builder::Init_Return_GetResult_Response_status();
}

}  // namespace celeste_interfaces


namespace celeste_interfaces
{

namespace action
{

namespace builder
{

class Init_Return_FeedbackMessage_feedback
{
public:
  explicit Init_Return_FeedbackMessage_feedback(::celeste_interfaces::action::Return_FeedbackMessage & msg)
  : msg_(msg)
  {}
  ::celeste_interfaces::action::Return_FeedbackMessage feedback(::celeste_interfaces::action::Return_FeedbackMessage::_feedback_type arg)
  {
    msg_.feedback = std::move(arg);
    return std::move(msg_);
  }

private:
  ::celeste_interfaces::action::Return_FeedbackMessage msg_;
};

class Init_Return_FeedbackMessage_goal_id
{
public:
  Init_Return_FeedbackMessage_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Return_FeedbackMessage_feedback goal_id(::celeste_interfaces::action::Return_FeedbackMessage::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_Return_FeedbackMessage_feedback(msg_);
  }

private:
  ::celeste_interfaces::action::Return_FeedbackMessage msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::celeste_interfaces::action::Return_FeedbackMessage>()
{
  return celeste_interfaces::action::builder::Init_Return_FeedbackMessage_goal_id();
}

}  // namespace celeste_interfaces

#endif  // CELESTE_INTERFACES__ACTION__DETAIL__RETURN__BUILDER_HPP_
