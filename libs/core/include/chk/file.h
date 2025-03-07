#pragma once

#include <chk/types.h>

typedef struct file {
  void *data;
  size_t size;
} file_t;

bool file_load(file_t *file, cstr_t path);
bool file_destroy(file_t *file);
