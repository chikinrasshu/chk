#include <chk/file.h>

#include <chk/log.h>

#include <stdio.h>
#include <stdlib.h>

bool file_load(file_t *file, cstr_t path) {
  bool result = false;

  if (file) {
    FILE *fptr = fopen(path, "rb");
    if (fptr) {
      fseek(fptr, 0, SEEK_END);
      file->size = ftell(fptr);
      fseek(fptr, 0, SEEK_SET);

      file->data = malloc(file->size);
      if (file->data) {
        if (fread(file->data, file->size, 1, fptr)) {
          result = true;
        } else {
          log_error("failed to read %zub from file '%s'", file->size, path);

          free(file->data);
          file->data = NULL;
          file->size = 0;
        }
      } else {
        log_error("failed to allocate %zub for file '%s'", file->size, path);

        file->size = 0;
      }
      fclose(fptr);
    } else {
      log_error("failed to open file '%s'", path);
    }
  } else {
    log_error("file was NULL");
  }

  return result;
}

bool file_destroy(file_t *file) {
  bool result = false;

  if (file) {
    if (file->data) {
      free(file->data);

      *file = (file_t){0};

      result = true;
    } else {
      log_error("file data was NULL");
    }
  } else {
    log_error("file was NULL");
  }

  return result;
}
