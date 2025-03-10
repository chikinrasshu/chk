#pragma once

#include <chk/types.h>

void format_str(Str buf, Size size, CStr str, ...);
void format_str_v(Str buf, Size size, CStr str, VarArgs args);
