#pragma once

#include <chk/core.h>

#include <chk/input.h>

#define WIN_CALLBACK(name) void name(void *user_ptr)
typedef WIN_CALLBACK(win_callback_t);

typedef input_t win_input_t;

typedef struct win_data {
  f32_t x, y;
  f32_t w, h;
  f32_t fb_w, fb_h;
  f32_t dpi_x, dpi_y;
  f32_t dt, _lt;
  u64_t frame_count;

  char caption[64];
} win_data_t;

typedef struct win_state {
  u32_t running : 1;
  u32_t hovered : 1;
  u32_t focused : 1;
  u32_t maximized : 1;
  u32_t minimized : 1;
} win_state_t;

typedef struct win_delta {
  u32_t pos : 1;
  u32_t size : 1;
  u32_t fb : 1;
  u32_t dpi : 1;

  u32_t hover : 1;
  u32_t focus : 1;
  u32_t minmax : 1;
} win_delta_t;

typedef struct win {
  win_data_t data;
  win_state_t is;
  win_delta_t changed;
  win_input_t input;

  void *_impl;
  void *_user_ptr;

  win_callback_t *_on_frame;
} win_t;

bool win_create(win_t *win, s32_t w, s32_t h, cstr_t caption);
bool win_destroy(win_t *win);

bool win_impl_set_caption(win_t *win, cstr_t caption);
bool win_impl_set_caption_f(win_t *win, cstr_t caption, ...);

#define win_set_caption(win, caption, ...)                                     \
  win_impl_set_caption##__VA_OPT__(_f)(win, caption __VA_OPT__(, ) __VA_ARGS__);

s32_t win_step(win_t *win, bool poll_events);
s32_t win_run(win_t *win, win_callback_t *on_frame, void *user_ptr);
