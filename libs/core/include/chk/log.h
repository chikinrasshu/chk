#pragma once

#ifndef LOG_BASEDIR
#define LOG_BASEDIR "/"
#endif

#include <chk/types.h>

typedef enum log_sev {
  log_sev_unknown = 0,
  log_sev_debug,
  log_sev_info,
  log_sev_warn,
  log_sev_error,
  log_sev_fatal,
} log_sev_t;

void log_raw(log_sev_t sev, cstr_t msg, cstr_t base, cstr_t file, u32_t line,
             cstr_t func);
void log_raw_v(log_sev_t sev, cstr_t msg, cstr_t base, cstr_t file, u32_t line,
               cstr_t func, va_list args);
void log_raw_f(log_sev_t sev, cstr_t msg, cstr_t base, cstr_t file, u32_t line,
               cstr_t func, ...);

#define log_debug(msg, ...)                                                    \
  log_raw##__VA_OPT__(_f)(log_sev_debug, msg, LOG_BASEDIR, __FILE__, __LINE__, \
                          __func__ __VA_OPT__(, ) __VA_ARGS__)
#define log_info(msg, ...)                                                     \
  log_raw##__VA_OPT__(_f)(log_sev_info, msg, LOG_BASEDIR, __FILE__, __LINE__,  \
                          __func__ __VA_OPT__(, ) __VA_ARGS__)
#define log_warn(msg, ...)                                                     \
  log_raw##__VA_OPT__(_f)(log_sev_warn, msg, LOG_BASEDIR, __FILE__, __LINE__,  \
                          __func__ __VA_OPT__(, ) __VA_ARGS__)
#define log_error(msg, ...)                                                    \
  log_raw##__VA_OPT__(_f)(log_sev_error, msg, LOG_BASEDIR, __FILE__, __LINE__, \
                          __func__ __VA_OPT__(, ) __VA_ARGS__)
#define log_fatal(msg, ...)                                                    \
  log_raw##__VA_OPT__(_f)(log_sev_fatal, msg, LOG_BASEDIR, __FILE__, __LINE__, \
                          __func__ __VA_OPT__(, ) __VA_ARGS__)
