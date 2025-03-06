#include "win_base.h"

void win_cb_on_close(GLFWwindow *_h) {
  win_t *win = glfwGetWindowUserPointer(_h);
  if (win) {
    win->is.running = false;
  }
}

void win_cb_on_frame(GLFWwindow *_h) {
  win_t *win = glfwGetWindowUserPointer(_h);
  if (win) {
    win_step(win, false);
  }
}

void win_cb_on_pos(GLFWwindow *_h, s32_t x, s32_t y) {
  win_t *win = glfwGetWindowUserPointer(_h);
  if (win) {
    win->data.x = x, win->data.y = y;
    win->changed.pos = true;
  }
}

void win_cb_on_size(GLFWwindow *_h, s32_t w, s32_t h) {
  win_t *win = glfwGetWindowUserPointer(_h);
  if (win) {
    win->data.w = w, win->data.h = h;
    win->changed.size = true;
  }
}

void win_cb_on_fb(GLFWwindow *_h, s32_t w, s32_t h) {
  win_t *win = glfwGetWindowUserPointer(_h);
  if (win) {
    win->data.fb_w = w, win->data.fb_h = h;
    win->changed.fb = true;
  }
}

void win_cb_on_dpi(GLFWwindow *_h, f32_t x, f32_t y) {
  win_t *win = glfwGetWindowUserPointer(_h);
  if (win) {
    win->data.dpi_x = x, win->data.dpi_y = y;
    win->changed.dpi = true;
  }
}

void win_cb_on_focus(GLFWwindow *_h, s32_t v) {
  win_t *win = glfwGetWindowUserPointer(_h);
  if (win) {
    win->is.focused = !!v;
    win->changed.focus = true;
  }
}

void win_cb_on_hover(GLFWwindow *_h, s32_t v) {
  win_t *win = glfwGetWindowUserPointer(_h);
  if (win) {
    win->is.hovered = !!v;
    win->changed.hover = true;
  }
}

void win_cb_on_min(GLFWwindow *_h, s32_t v) {
  win_t *win = glfwGetWindowUserPointer(_h);
  if (win) {
    win->is.minimized = !!v;
    win->changed.minmax = true;
  }
}

void win_cb_on_max(GLFWwindow *_h, s32_t v) {
  win_t *win = glfwGetWindowUserPointer(_h);
  if (win) {
    win->is.maximized = !!v;
    win->changed.minmax = true;
  }
}

void win_cb_on_mouse_pos(GLFWwindow *_h, f64_t x, f64_t y) {
  win_t *win = glfwGetWindowUserPointer(_h);
  if (win) {
    mouse_t *mouse = &win->input.mouse;
    mouse->dx = (f32_t)x - mouse->x, mouse->dy = (f32_t)y - mouse->y;
    mouse->x = (f32_t)x, mouse->y = (f32_t)y;
  }
}

void win_cb_on_mouse_btn(GLFWwindow *_h, s32_t b, s32_t a, s32_t m) {
  win_t *win = glfwGetWindowUserPointer(_h);
  if (win) {
    size_t i = win_input_mouse_from_impl(b);
    btn_t *btn = &win->input.mouse.btns[i];

    switch (a) {
    case GLFW_PRESS:
      btn->is_down = true, btn->is_pressed = true;
      break;
    case GLFW_RELEASE:
      btn->is_down = false, btn->is_pressed = false;
      break;
    }
  }
}

void win_cb_on_kbd_key(GLFWwindow *_h, s32_t k, s32_t sc, s32_t a, s32_t m) {
  win_t *win = glfwGetWindowUserPointer(_h);
  if (win) {
    size_t i = win_input_mouse_from_impl(k);
    key_t *key = &win->input.kbd.keys[i];

    switch (a) {
    case GLFW_PRESS:
      key->is_down = true, key->is_pressed = true;
      break;
    case GLFW_RELEASE:
      key->is_down = false, key->is_pressed = false;
      break;
    }
  }
}

void win_cb_kbd_unicode(GLFWwindow *_h, u32_t c) {
  win_t *win = glfwGetWindowUserPointer(_h);
  if (win) {
  }
}
