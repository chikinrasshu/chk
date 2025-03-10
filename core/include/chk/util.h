#pragma once

#include <chk/types.h>

#define countof(n) (sizeof(n) / sizeof((n)[0]))

#define kilobytes(n) (1024ULL * (n))
#define megabytes(n) (1024ULL * kilobytes(n))
#define gigabytes(n) (1024ULL * megabytes(n))
#define terabytes(n) (1024ULL * gigabytes(n))

void size_to_str(Str buf, Size buf_size, U64 n);
