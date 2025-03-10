#include <chk/fmt.h>

#include <stdio.h>

void format_str(Str buf, Size size, CStr str, ...) {
  VarArgs args;
  va_start(args, str);

  format_str_v(buf, size, str, args);

  va_end(args);
}

void format_str_v(Str buf, Size size, CStr str, VarArgs args) {
  VarArgs args_copy;
  va_copy(args_copy, args);

  vsnprintf(buf, size, str, args_copy);

  va_end(args_copy);
}
