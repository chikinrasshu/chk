#pragma once

#include <chk/types.h>

void fmt_str_v(str_t buf, size_t size, cstr_t msg, va_list args);
void fmt_str(str_t buf, size_t size, cstr_t msg, ...);
