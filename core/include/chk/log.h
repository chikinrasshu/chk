#pragma once

#include <chk/types.h>

#ifndef LOG_BASEPATH
#error "Please define LOG_BASEPATH to at least \"/\""
#endif

typedef enum {
  LogSev_Unknown,

  LogSev_Debug,
  LogSev_Info,
  LogSev_Warn,
  LogSev_Error,

  LogSev_COUNT
} LogSev;

void log_raw(LogSev sev, CStr msg, CStr base, CStr file, U32 line, CStr func);
void log_raw_f(LogSev sev, CStr msg, CStr base, CStr file, U32 line, CStr func,
               ...);
void log_raw_v(LogSev sev, CStr msg, CStr base, CStr file, U32 line, CStr func,
               VarArgs a);

#define log_debug(msg, ...)                                                    \
  log_raw##__VA_OPT__(_f)(LogSev_Debug, msg, LOG_BASEPATH, __FILE__, __LINE__, \
                          __func__ __VA_OPT__(, ) __VA_ARGS__)
#define log_info(msg, ...)                                                     \
  log_raw##__VA_OPT__(_f)(LogSev_Info, msg, LOG_BASEPATH, __FILE__, __LINE__,  \
                          __func__ __VA_OPT__(, ) __VA_ARGS__)
#define log_warn(msg, ...)                                                     \
  log_raw##__VA_OPT__(_f)(LogSev_Warn, msg, LOG_BASEPATH, __FILE__, __LINE__,  \
                          __func__ __VA_OPT__(, ) __VA_ARGS__)
#define log_error(msg, ...)                                                    \
  log_raw##__VA_OPT__(_f)(LogSev_Error, msg, LOG_BASEPATH, __FILE__, __LINE__, \
                          __func__ __VA_OPT__(, ) __VA_ARGS__)
