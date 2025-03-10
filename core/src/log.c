#include <chk/log.h>

#include <chk/fmt.h>
#include <chk/util.h>

#include <cwalk.h>

#include <stdio.h>

void log_raw(LogSev sev, CStr msg, CStr base, CStr file, U32 line, CStr func) {
  static Ch buf[1024];

  CStr sev_name;
  switch (sev) {
  default:
    sev_name = "Unkn";
    break;
  case LogSev_Debug:
    sev_name = "Debug";
    break;
  case LogSev_Info:
    sev_name = "Info";
    break;
  case LogSev_Warn:
    sev_name = "Warn";
    break;
  case LogSev_Error:
    sev_name = "Error";
    break;
  }

  static Ch rel_file[260];
  cwk_path_get_relative(base, file, rel_file, countof(rel_file));

  format_str(buf, countof(buf), "[%s] [%s:%u:%s] %s\n", //
             sev_name, rel_file, line, func, msg);

  fputs(buf, stderr);
}

void log_raw_f(LogSev sev, CStr msg, CStr base, CStr file, U32 line, CStr func,
               ...) {
  VarArgs args;
  va_start(args, func);
  log_raw_v(sev, msg, base, file, line, func, args);
  va_end(args);
}

void log_raw_v(LogSev sev, CStr msg, CStr base, CStr file, U32 line, CStr func,
               VarArgs args) {
  static Ch buf[1024];

  VarArgs args_copy;
  va_copy(args_copy, args);
  format_str_v(buf, countof(buf), msg, args_copy);
  va_end(args_copy);

  log_raw(sev, buf, base, file, line, func);
}
