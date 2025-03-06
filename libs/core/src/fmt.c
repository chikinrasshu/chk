#include <chk/fmt.h>
#include <stdio.h>

void fmt_str_v(str_t buf, size_t size, cstr_t msg, va_list args) {
  va_list args2;
  va_copy(args2, args);
  vsnprintf(buf, size, msg, args2);
  va_end(args2);
}

void fmt_str(str_t buf, size_t size, cstr_t msg, ...) {
  va_list args;
  va_start(args, msg);
  fmt_str_v(buf, size, msg, args);
  va_end(args);
}
