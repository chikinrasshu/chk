#pragma once

#define countof(a) (sizeof(a) / sizeof((a)[0]))

#define kilobytes(n) (1024ULL * (n))
#define megabytes(n) (1024ULL * kilobytes(n))
#define gigabytes(n) (1024ULL * megabytes(n))
#define terabytes(n) (1024ULL * gigabytes(n))
