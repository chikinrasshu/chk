#include <chk/launcher.h>

WIN_CALLBACK(launcher_cb_on_frame) {
  launcher_t *l = user_ptr;
  if (l) {
    renderer_begin_frame(&l->renderer);

    if (l->_on_frame) {
      l->_on_frame(l->_user_ptr);
    }

    renderer_end_frame(&l->renderer);
  }
}

bool launcher_create(launcher_t *l) {
  bool result = false;

  if (l) {
    if (win_create(&l->win, 800, 600, "chk_launcher")) {
      if (renderer_create(&l->renderer, 1024)) {

        result = true;
      } else {
        log_error("failed to create the main renderer");
      }
    } else {
      log_error("failed to create the main window");
    }
  } else {
    log_error("launcher was NULL");
  }

  return result;
}

bool launcher_destroy(launcher_t *l) {
  bool result = false;

  if (l) {
    if (renderer_destroy(&l->renderer)) {
      if (win_destroy(&l->win)) {

        *l = (launcher_t){0};

        result = true;
      } else {
        log_error("failed to destroy the main window");
      }
    } else {
      log_error("failed to destroy the main renderer");
    }
  } else {
    log_error("launcher was NULL");
  }

  return result;
}

s32_t launcher_run(launcher_t *l, win_callback_t *on_frame, void *user_ptr) {
  s32_t result = 1;

  if (l) {
    l->_on_frame = on_frame;
    l->_user_ptr = user_ptr;

    result = win_run(&l->win, launcher_cb_on_frame, l);
  } else {
    log_error("launcher was NULL");
  }

  return result;
}
