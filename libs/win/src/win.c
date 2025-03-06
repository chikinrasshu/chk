#include "chk/input.h"
#include "glad/gl.h"
#include "win_base.h"

static s32_t g_win_count = 0;

bool win_create(win_t *win, s32_t w, s32_t h, cstr_t caption) {
  bool result = false;

  if (!g_win_count) {
    if (glfwInit()) {
      log_info("win subsystem initialized");
    } else {
      log_error("win subsystem could not be initialized");
    }
  }

  ++g_win_count;
  log_debug("global win count is now '%d'", g_win_count);

  if (g_win_count > 0) {
    if (win) {
      *win = (win_t){0};

      glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);

      glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_API);
      glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, CHK_GL_MAJOR);
      glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, CHK_GL_MINOR);
      glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
      glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

      win->_impl = glfwCreateWindow(w, h, caption, NULL, NULL);
      if (win->_impl) {
        log_info("win '%s' created", caption);

        glfwMakeContextCurrent(win->_impl);
        s32_t gl = gladLoadGL(glfwGetProcAddress);
        if (gl) {
          log_info("opengl %d.%d initialized", //
                   GLAD_VERSION_MAJOR(gl), GLAD_VERSION_MINOR(gl));

          s32_t tmp_a, tmp_b;
          f32_t tmp_c, tmp_d;
          glfwGetWindowPos(win->_impl, &tmp_a, &tmp_b);
          win->data.x = (s32_t)tmp_a, win->data.y = (s32_t)tmp_b;
          glfwGetWindowSize(win->_impl, &tmp_a, &tmp_b);
          win->data.w = (s32_t)tmp_a, win->data.h = (s32_t)tmp_b;
          glfwGetFramebufferSize(win->_impl, &tmp_a, &tmp_b);
          win->data.fb_w = (f32_t)tmp_a, win->data.fb_h = (f32_t)tmp_b;
          glfwGetWindowContentScale(win->_impl, &tmp_c, &tmp_d);
          win->data.dpi_x = (f32_t)tmp_c, win->data.dpi_y = (f32_t)tmp_d;

          glfwSetWindowUserPointer(win->_impl, win);
          glfwSetWindowCloseCallback(win->_impl, win_cb_on_close);
          glfwSetWindowRefreshCallback(win->_impl, win_cb_on_frame);
          glfwSetWindowPosCallback(win->_impl, win_cb_on_pos);
          glfwSetWindowSizeCallback(win->_impl, win_cb_on_size);
          glfwSetFramebufferSizeCallback(win->_impl, win_cb_on_fb);
          glfwSetWindowContentScaleCallback(win->_impl, win_cb_on_dpi);
          glfwSetWindowFocusCallback(win->_impl, win_cb_on_focus);
          glfwSetCursorEnterCallback(win->_impl, win_cb_on_hover);
          glfwSetWindowIconifyCallback(win->_impl, win_cb_on_min);
          glfwSetWindowMaximizeCallback(win->_impl, win_cb_on_max);
          glfwSetCursorPosCallback(win->_impl, win_cb_on_mouse_pos);
          glfwSetMouseButtonCallback(win->_impl, win_cb_on_mouse_btn);
          glfwSetKeyCallback(win->_impl, win_cb_on_kbd_key);
          glfwSetCharCallback(win->_impl, win_cb_kbd_unicode);

          log_debug("win '%s' initialized", caption);
          win->is.running = true;
          result = true;
        } else {
          log_error("opengl could not be initialized");
        }
      } else {
        log_error("win '%s' could not be created", caption);
      }
    } else {
      log_error("win was NULL");
    }
  } else {
    log_error("win subsystem was not initialized");
  }

  return result;
}

bool win_destroy(win_t *win) {
  bool result = false;

  if (win) {
    if (win->_impl) {
      glfwDestroyWindow(win->_impl);

      --g_win_count;
      log_debug("global win count is now '%d'", g_win_count);

      if (!g_win_count) {
        glfwTerminate();
        log_debug("win ran for %llu frames", win->data.frame_count);
        log_info("win subsystem terminated");
      }

      *win = (win_t){0};
      result = true;
    } else {
      log_error("win was not initialized");
    }
  } else {
    log_error("win was NULL");
  }

  return result;
}

s32_t win_step(win_t *win, bool poll_events) {
  s32_t result = 1;

  if (win) {
    if (win->is.running) {
      if (poll_events) {
        glfwPollEvents();
      }

      glViewport(0, 0, win->data.fb_w, win->data.fb_h);
      glClearColor(0.1f, 0.2f, 0.3f, 1.0f);
      glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

      if (win->_on_frame) {
        win->_on_frame(win->_user_ptr);
      }

      for (size_t i = 0; i < countof(win->input.mouse.btns); ++i) {
        btn_t *btn = win->input.mouse.btns + i;
        btn->is_pressed = false;
        btn->is_released = false;
      }

      for (size_t i = 0; i < countof(win->input.kbd.keys); ++i) {
        key_t *key = win->input.kbd.keys + i;
        key->is_pressed = false;
        key->is_released = false;
      }

      for (size_t g = 0; g < countof(win->input.gamepad); ++g) {
        for (size_t i = 0; i < countof(win->input.gamepad[g].btns); ++i) {
          btn_t *btn = win->input.gamepad[g].btns + i;
          btn->is_pressed = false;
          btn->is_released = false;
        }
      }

      glfwSwapBuffers(win->_impl);
      win->data.frame_count++;

      f64_t ct = glfwGetTime();
      win->data.dt = ct - win->data._lt;
      win->data._lt = ct;

      win->changed = (win_delta_t){0};

      result = 0;
    }
  } else {
    log_error("win was NULL");
  }

  return result;
}

s32_t win_run(win_t *win, win_callback_t on_frame, void *user_ptr) {
  s32_t result = 1;

  if (win) {
    if (win->is.running) {
      win->_on_frame = on_frame;
      win->_user_ptr = user_ptr;

      glfwShowWindow(win->_impl);
      while (win->is.running) {
        result = win_step(win, true);
      }
    } else {
      log_error("win was not initialized");
    }
  } else {
    log_error("win was NULL");
  }

  return result;
}
