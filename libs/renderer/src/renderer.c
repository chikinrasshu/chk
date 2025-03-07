#include <chk/renderer.h>

#include <chk/log.h>

bool renderer_create(renderer_t *r, size_t max_cmds) {
  bool result = false;

  (void)max_cmds;

  if (r) {

    result = true;
  } else {
    log_error("renderer was NULL");
  }

  return result;
}

bool renderer_destroy(renderer_t *r) {
  bool result = false;

  if (r) {

    *r = (renderer_t){0};

    result = true;
  } else {
    log_error("renderer was NULL");
  }

  return result;
}

bool renderer_begin_frame(renderer_t *r) {
  bool result = false;

  if (r) {

    result = true;
  } else {
    log_error("renderer was NULL");
  }

  return result;
}

bool renderer_end_frame(renderer_t *r) {
  bool result = false;

  if (r) {

    result = true;
  } else {
    log_error("renderer was NULL");
  }

  return result;
}
