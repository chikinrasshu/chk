#include <chk/fmt.h>
#include <chk/log.h>

#include <stdio.h>
#include <stdlib.h>

#include <cwalk.h>

void log_raw(log_sev_t sev, cstr_t msg, cstr_t base, cstr_t file, u32_t line,
             cstr_t func) {
  static char buf[1024];

  // Get sev name and color codes
  cstr_t sev_name = "", col_a = "", col_b = "";
  switch (sev) {
  case log_sev_unknown:
    sev_name = "Unkn";
    col_a = "\x1b[1;30m", col_b = "\x1b[0m";
    break;
  case log_sev_debug:
    sev_name = "Debug";
    col_a = "\x1b[2m", col_b = "\x1b[22m";
    break;
  case log_sev_info:
    sev_name = "Info";
    col_a = "\x1b[0;34m", col_b = "\x1b[0m";
    break;
  case log_sev_warn:
    sev_name = "Warn";
    col_a = "\x1b[0;33m", col_b = "\x1b[0m";
    break;
  case log_sev_error:
    sev_name = "Error";
    col_a = "\x1b[0;31m", col_b = "\x1b[0m";
    break;
  case log_sev_fatal:
    sev_name = "Fatal";
    col_a = "\x1b[1;31m", col_b = "\x1b[0m";
    break;
  }

  // Get relative path
  static char rel[260];
  cwk_path_get_relative(base, file, rel, sizeof(rel));

  // Format the log and print
  fmt_str(buf, sizeof(buf), "%s[%s] [%s:%d:%s] %s%s\n", //
          col_a, sev_name, rel, line, func, msg, col_b);
  fputs(buf, stderr);

  // Abort if sev is fatal
  if (sev == log_sev_fatal) {
    exit(1);
  }
}

void log_raw_v(log_sev_t sev, cstr_t msg, cstr_t base, cstr_t file, u32_t line,
               cstr_t func, va_list args) {
  static char buf[1024];

  va_list args2;
  va_copy(args2, args);
  fmt_str_v(buf, sizeof(buf), msg, args2);
  va_end(args2);

  log_raw(sev, buf, base, file, line, func);
}

void log_raw_f(log_sev_t sev, cstr_t msg, cstr_t base, cstr_t file, u32_t line,
               cstr_t func, ...) {
  va_list args;
  va_start(args, func);
  log_raw_v(sev, msg, base, file, line, func, args);
  va_end(args);
}
