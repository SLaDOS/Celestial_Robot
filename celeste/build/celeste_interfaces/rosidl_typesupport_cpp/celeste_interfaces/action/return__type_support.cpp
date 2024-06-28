// generated from rosidl_typesupport_cpp/resource/idl__type_support.cpp.em
// with input from celeste_interfaces:action/Return.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "celeste_interfaces/action/detail/return__struct.hpp"
#include "rosidl_typesupport_cpp/identifier.hpp"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
#include "rosidl_typesupport_cpp/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace celeste_interfaces
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _Return_Goal_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Return_Goal_type_support_ids_t;

static const _Return_Goal_type_support_ids_t _Return_Goal_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _Return_Goal_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Return_Goal_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Return_Goal_type_support_symbol_names_t _Return_Goal_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, celeste_interfaces, action, Return_Goal)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, celeste_interfaces, action, Return_Goal)),
  }
};

typedef struct _Return_Goal_type_support_data_t
{
  void * data[2];
} _Return_Goal_type_support_data_t;

static _Return_Goal_type_support_data_t _Return_Goal_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Return_Goal_message_typesupport_map = {
  2,
  "celeste_interfaces",
  &_Return_Goal_message_typesupport_ids.typesupport_identifier[0],
  &_Return_Goal_message_typesupport_symbol_names.symbol_name[0],
  &_Return_Goal_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t Return_Goal_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Return_Goal_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace celeste_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<celeste_interfaces::action::Return_Goal>()
{
  return &::celeste_interfaces::action::rosidl_typesupport_cpp::Return_Goal_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, celeste_interfaces, action, Return_Goal)() {
  return get_message_type_support_handle<celeste_interfaces::action::Return_Goal>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "celeste_interfaces/action/detail/return__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace celeste_interfaces
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _Return_Result_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Return_Result_type_support_ids_t;

static const _Return_Result_type_support_ids_t _Return_Result_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _Return_Result_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Return_Result_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Return_Result_type_support_symbol_names_t _Return_Result_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, celeste_interfaces, action, Return_Result)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, celeste_interfaces, action, Return_Result)),
  }
};

typedef struct _Return_Result_type_support_data_t
{
  void * data[2];
} _Return_Result_type_support_data_t;

static _Return_Result_type_support_data_t _Return_Result_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Return_Result_message_typesupport_map = {
  2,
  "celeste_interfaces",
  &_Return_Result_message_typesupport_ids.typesupport_identifier[0],
  &_Return_Result_message_typesupport_symbol_names.symbol_name[0],
  &_Return_Result_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t Return_Result_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Return_Result_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace celeste_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<celeste_interfaces::action::Return_Result>()
{
  return &::celeste_interfaces::action::rosidl_typesupport_cpp::Return_Result_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, celeste_interfaces, action, Return_Result)() {
  return get_message_type_support_handle<celeste_interfaces::action::Return_Result>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "celeste_interfaces/action/detail/return__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace celeste_interfaces
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _Return_Feedback_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Return_Feedback_type_support_ids_t;

static const _Return_Feedback_type_support_ids_t _Return_Feedback_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _Return_Feedback_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Return_Feedback_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Return_Feedback_type_support_symbol_names_t _Return_Feedback_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, celeste_interfaces, action, Return_Feedback)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, celeste_interfaces, action, Return_Feedback)),
  }
};

typedef struct _Return_Feedback_type_support_data_t
{
  void * data[2];
} _Return_Feedback_type_support_data_t;

static _Return_Feedback_type_support_data_t _Return_Feedback_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Return_Feedback_message_typesupport_map = {
  2,
  "celeste_interfaces",
  &_Return_Feedback_message_typesupport_ids.typesupport_identifier[0],
  &_Return_Feedback_message_typesupport_symbol_names.symbol_name[0],
  &_Return_Feedback_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t Return_Feedback_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Return_Feedback_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace celeste_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<celeste_interfaces::action::Return_Feedback>()
{
  return &::celeste_interfaces::action::rosidl_typesupport_cpp::Return_Feedback_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, celeste_interfaces, action, Return_Feedback)() {
  return get_message_type_support_handle<celeste_interfaces::action::Return_Feedback>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "celeste_interfaces/action/detail/return__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace celeste_interfaces
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _Return_SendGoal_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Return_SendGoal_Request_type_support_ids_t;

static const _Return_SendGoal_Request_type_support_ids_t _Return_SendGoal_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _Return_SendGoal_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Return_SendGoal_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Return_SendGoal_Request_type_support_symbol_names_t _Return_SendGoal_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, celeste_interfaces, action, Return_SendGoal_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, celeste_interfaces, action, Return_SendGoal_Request)),
  }
};

typedef struct _Return_SendGoal_Request_type_support_data_t
{
  void * data[2];
} _Return_SendGoal_Request_type_support_data_t;

static _Return_SendGoal_Request_type_support_data_t _Return_SendGoal_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Return_SendGoal_Request_message_typesupport_map = {
  2,
  "celeste_interfaces",
  &_Return_SendGoal_Request_message_typesupport_ids.typesupport_identifier[0],
  &_Return_SendGoal_Request_message_typesupport_symbol_names.symbol_name[0],
  &_Return_SendGoal_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t Return_SendGoal_Request_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Return_SendGoal_Request_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace celeste_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<celeste_interfaces::action::Return_SendGoal_Request>()
{
  return &::celeste_interfaces::action::rosidl_typesupport_cpp::Return_SendGoal_Request_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, celeste_interfaces, action, Return_SendGoal_Request)() {
  return get_message_type_support_handle<celeste_interfaces::action::Return_SendGoal_Request>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "celeste_interfaces/action/detail/return__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace celeste_interfaces
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _Return_SendGoal_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Return_SendGoal_Response_type_support_ids_t;

static const _Return_SendGoal_Response_type_support_ids_t _Return_SendGoal_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _Return_SendGoal_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Return_SendGoal_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Return_SendGoal_Response_type_support_symbol_names_t _Return_SendGoal_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, celeste_interfaces, action, Return_SendGoal_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, celeste_interfaces, action, Return_SendGoal_Response)),
  }
};

typedef struct _Return_SendGoal_Response_type_support_data_t
{
  void * data[2];
} _Return_SendGoal_Response_type_support_data_t;

static _Return_SendGoal_Response_type_support_data_t _Return_SendGoal_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Return_SendGoal_Response_message_typesupport_map = {
  2,
  "celeste_interfaces",
  &_Return_SendGoal_Response_message_typesupport_ids.typesupport_identifier[0],
  &_Return_SendGoal_Response_message_typesupport_symbol_names.symbol_name[0],
  &_Return_SendGoal_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t Return_SendGoal_Response_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Return_SendGoal_Response_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace celeste_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<celeste_interfaces::action::Return_SendGoal_Response>()
{
  return &::celeste_interfaces::action::rosidl_typesupport_cpp::Return_SendGoal_Response_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, celeste_interfaces, action, Return_SendGoal_Response)() {
  return get_message_type_support_handle<celeste_interfaces::action::Return_SendGoal_Response>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "celeste_interfaces/action/detail/return__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_cpp/service_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace celeste_interfaces
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _Return_SendGoal_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Return_SendGoal_type_support_ids_t;

static const _Return_SendGoal_type_support_ids_t _Return_SendGoal_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _Return_SendGoal_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Return_SendGoal_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Return_SendGoal_type_support_symbol_names_t _Return_SendGoal_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, celeste_interfaces, action, Return_SendGoal)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, celeste_interfaces, action, Return_SendGoal)),
  }
};

typedef struct _Return_SendGoal_type_support_data_t
{
  void * data[2];
} _Return_SendGoal_type_support_data_t;

static _Return_SendGoal_type_support_data_t _Return_SendGoal_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Return_SendGoal_service_typesupport_map = {
  2,
  "celeste_interfaces",
  &_Return_SendGoal_service_typesupport_ids.typesupport_identifier[0],
  &_Return_SendGoal_service_typesupport_symbol_names.symbol_name[0],
  &_Return_SendGoal_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t Return_SendGoal_service_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Return_SendGoal_service_typesupport_map),
  ::rosidl_typesupport_cpp::get_service_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace celeste_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
get_service_type_support_handle<celeste_interfaces::action::Return_SendGoal>()
{
  return &::celeste_interfaces::action::rosidl_typesupport_cpp::Return_SendGoal_service_type_support_handle;
}

}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "celeste_interfaces/action/detail/return__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace celeste_interfaces
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _Return_GetResult_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Return_GetResult_Request_type_support_ids_t;

static const _Return_GetResult_Request_type_support_ids_t _Return_GetResult_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _Return_GetResult_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Return_GetResult_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Return_GetResult_Request_type_support_symbol_names_t _Return_GetResult_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, celeste_interfaces, action, Return_GetResult_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, celeste_interfaces, action, Return_GetResult_Request)),
  }
};

typedef struct _Return_GetResult_Request_type_support_data_t
{
  void * data[2];
} _Return_GetResult_Request_type_support_data_t;

static _Return_GetResult_Request_type_support_data_t _Return_GetResult_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Return_GetResult_Request_message_typesupport_map = {
  2,
  "celeste_interfaces",
  &_Return_GetResult_Request_message_typesupport_ids.typesupport_identifier[0],
  &_Return_GetResult_Request_message_typesupport_symbol_names.symbol_name[0],
  &_Return_GetResult_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t Return_GetResult_Request_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Return_GetResult_Request_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace celeste_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<celeste_interfaces::action::Return_GetResult_Request>()
{
  return &::celeste_interfaces::action::rosidl_typesupport_cpp::Return_GetResult_Request_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, celeste_interfaces, action, Return_GetResult_Request)() {
  return get_message_type_support_handle<celeste_interfaces::action::Return_GetResult_Request>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "celeste_interfaces/action/detail/return__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace celeste_interfaces
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _Return_GetResult_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Return_GetResult_Response_type_support_ids_t;

static const _Return_GetResult_Response_type_support_ids_t _Return_GetResult_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _Return_GetResult_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Return_GetResult_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Return_GetResult_Response_type_support_symbol_names_t _Return_GetResult_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, celeste_interfaces, action, Return_GetResult_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, celeste_interfaces, action, Return_GetResult_Response)),
  }
};

typedef struct _Return_GetResult_Response_type_support_data_t
{
  void * data[2];
} _Return_GetResult_Response_type_support_data_t;

static _Return_GetResult_Response_type_support_data_t _Return_GetResult_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Return_GetResult_Response_message_typesupport_map = {
  2,
  "celeste_interfaces",
  &_Return_GetResult_Response_message_typesupport_ids.typesupport_identifier[0],
  &_Return_GetResult_Response_message_typesupport_symbol_names.symbol_name[0],
  &_Return_GetResult_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t Return_GetResult_Response_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Return_GetResult_Response_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace celeste_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<celeste_interfaces::action::Return_GetResult_Response>()
{
  return &::celeste_interfaces::action::rosidl_typesupport_cpp::Return_GetResult_Response_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, celeste_interfaces, action, Return_GetResult_Response)() {
  return get_message_type_support_handle<celeste_interfaces::action::Return_GetResult_Response>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "celeste_interfaces/action/detail/return__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/service_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace celeste_interfaces
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _Return_GetResult_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Return_GetResult_type_support_ids_t;

static const _Return_GetResult_type_support_ids_t _Return_GetResult_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _Return_GetResult_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Return_GetResult_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Return_GetResult_type_support_symbol_names_t _Return_GetResult_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, celeste_interfaces, action, Return_GetResult)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, celeste_interfaces, action, Return_GetResult)),
  }
};

typedef struct _Return_GetResult_type_support_data_t
{
  void * data[2];
} _Return_GetResult_type_support_data_t;

static _Return_GetResult_type_support_data_t _Return_GetResult_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Return_GetResult_service_typesupport_map = {
  2,
  "celeste_interfaces",
  &_Return_GetResult_service_typesupport_ids.typesupport_identifier[0],
  &_Return_GetResult_service_typesupport_symbol_names.symbol_name[0],
  &_Return_GetResult_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t Return_GetResult_service_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Return_GetResult_service_typesupport_map),
  ::rosidl_typesupport_cpp::get_service_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace celeste_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
get_service_type_support_handle<celeste_interfaces::action::Return_GetResult>()
{
  return &::celeste_interfaces::action::rosidl_typesupport_cpp::Return_GetResult_service_type_support_handle;
}

}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "celeste_interfaces/action/detail/return__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace celeste_interfaces
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _Return_FeedbackMessage_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Return_FeedbackMessage_type_support_ids_t;

static const _Return_FeedbackMessage_type_support_ids_t _Return_FeedbackMessage_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _Return_FeedbackMessage_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Return_FeedbackMessage_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Return_FeedbackMessage_type_support_symbol_names_t _Return_FeedbackMessage_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, celeste_interfaces, action, Return_FeedbackMessage)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, celeste_interfaces, action, Return_FeedbackMessage)),
  }
};

typedef struct _Return_FeedbackMessage_type_support_data_t
{
  void * data[2];
} _Return_FeedbackMessage_type_support_data_t;

static _Return_FeedbackMessage_type_support_data_t _Return_FeedbackMessage_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Return_FeedbackMessage_message_typesupport_map = {
  2,
  "celeste_interfaces",
  &_Return_FeedbackMessage_message_typesupport_ids.typesupport_identifier[0],
  &_Return_FeedbackMessage_message_typesupport_symbol_names.symbol_name[0],
  &_Return_FeedbackMessage_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t Return_FeedbackMessage_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Return_FeedbackMessage_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace celeste_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<celeste_interfaces::action::Return_FeedbackMessage>()
{
  return &::celeste_interfaces::action::rosidl_typesupport_cpp::Return_FeedbackMessage_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, celeste_interfaces, action, Return_FeedbackMessage)() {
  return get_message_type_support_handle<celeste_interfaces::action::Return_FeedbackMessage>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

#include "action_msgs/msg/goal_status_array.hpp"
#include "action_msgs/srv/cancel_goal.hpp"
// already included above
// #include "celeste_interfaces/action/detail/return__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
#include "rosidl_runtime_c/action_type_support_struct.h"
#include "rosidl_typesupport_cpp/action_type_support.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_cpp/service_type_support.hpp"

namespace celeste_interfaces
{

namespace action
{

namespace rosidl_typesupport_cpp
{

static rosidl_action_type_support_t Return_action_type_support_handle = {
  NULL, NULL, NULL, NULL, NULL};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace celeste_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_action_type_support_t *
get_action_type_support_handle<celeste_interfaces::action::Return>()
{
  using ::celeste_interfaces::action::rosidl_typesupport_cpp::Return_action_type_support_handle;
  // Thread-safe by always writing the same values to the static struct
  Return_action_type_support_handle.goal_service_type_support = get_service_type_support_handle<::celeste_interfaces::action::Return::Impl::SendGoalService>();
  Return_action_type_support_handle.result_service_type_support = get_service_type_support_handle<::celeste_interfaces::action::Return::Impl::GetResultService>();
  Return_action_type_support_handle.cancel_service_type_support = get_service_type_support_handle<::celeste_interfaces::action::Return::Impl::CancelGoalService>();
  Return_action_type_support_handle.feedback_message_type_support = get_message_type_support_handle<::celeste_interfaces::action::Return::Impl::FeedbackMessage>();
  Return_action_type_support_handle.status_message_type_support = get_message_type_support_handle<::celeste_interfaces::action::Return::Impl::GoalStatusMessage>();
  return &Return_action_type_support_handle;
}

}  // namespace rosidl_typesupport_cpp
