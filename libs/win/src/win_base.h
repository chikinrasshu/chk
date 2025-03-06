#pragma once

#include <chk/win.h>

#ifndef CHK_GL_MAJOR
#define CHK_GL_MAJOR 4
#endif
#ifndef CHK_GL_MINOR
#define CHK_GL_MINOR 1
#endif

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/gl.h>

void win_cb_on_close(GLFWwindow *_h);
void win_cb_on_frame(GLFWwindow *_h);
void win_cb_on_pos(GLFWwindow *_h, s32_t x, s32_t y);
void win_cb_on_size(GLFWwindow *_h, s32_t w, s32_t h);
void win_cb_on_fb(GLFWwindow *_h, s32_t w, s32_t h);
void win_cb_on_dpi(GLFWwindow *_h, f32_t x, f32_t y);
void win_cb_on_focus(GLFWwindow *_h, s32_t v);
void win_cb_on_hover(GLFWwindow *_h, s32_t v);
void win_cb_on_min(GLFWwindow *_h, s32_t v);
void win_cb_on_max(GLFWwindow *_h, s32_t v);
void win_cb_on_mouse_pos(GLFWwindow *_h, f64_t x, f64_t y);
void win_cb_on_mouse_btn(GLFWwindow *_h, s32_t b, s32_t a, s32_t m);
void win_cb_on_kbd_key(GLFWwindow *_h, s32_t k, s32_t sc, s32_t a, s32_t m);
void win_cb_kbd_unicode(GLFWwindow *_h, u32_t c);

size_t win_input_mouse_from_impl(u32_t impl_id);
size_t win_input_kbd_from_impl(u32_t impl_id);
size_t win_input_gamepad_from_impl(u32_t impl_id);
