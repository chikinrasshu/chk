#include <chk/file.h>

#include <chk/log.h>
#include <chk/memory.h>
#include <chk/util.h>

#include <stdio.h>

File load_file(CStr path) {
  File file = {0};

  if (path) {
    FILE *fptr = fopen(path, "rb");
    if (fptr) {
      fseek(fptr, 0, SEEK_END);
      long size = ftell(fptr);
      fseek(fptr, 0, SEEK_SET);

      file.data = get_memory(size);
      if (file.data) {
        if (fread(file.data, size, 1, fptr)) {
          file.size = (Size)size;
          file.initted = true;
        } else {
          char size_str[64];
          size_to_str(size_str, countof(size_str), size);
          log_error("failed to read %s from the file %s", size_str, path);

          free_memory(file.data);
          file.data = NULL;
        }
      } else {
        char size_str[64];
        size_to_str(size_str, countof(size_str), size);
        log_error("failed to allocate %s for the file '%s'", size_str, path);
      }

      fclose(fptr);
    } else {
      log_error("failed to open file '%s'", path);
    }
  } else {
    log_error("path was NULL");
  }

  return file;
}

void free_file(File *file) {
  if (file) {
    if (file->initted) {
      if (file->data && file->size) {
        free_memory(file->data);

        *file = (File){0};
      } else {
        log_error("file was empty");
      }
    } else {
      log_error("file was not initialized");
    }
  } else {
    log_error("file was NULL");
  }
}
