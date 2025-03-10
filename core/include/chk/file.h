#pragma once

#include <chk/types.h>

typedef struct {
  bool initted;

  void *data;
  size_t size;
} File;

File load_file(CStr path);
void free_file(File *file);
