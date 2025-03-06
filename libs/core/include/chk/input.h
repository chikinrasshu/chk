#pragma once

#include <chk/types.h>

typedef enum mouse_btn {
  mouse_btn_unknown = 0,

  //

  mouse_btn_count,
} mouse_btn_t;

typedef enum kbd_key {
  kbd_key_unknown = 0,

  //

  kbd_key_count,
} kbd_key_t;

typedef enum gamepad_btn {
  gamepad_btn_unknown = 0,

  //

  gamepad_btn_count,
} gamepad_btn_t;

typedef struct pressable {
  bool is_down;
  bool is_pressed;
  bool is_released;
} btn_t, key_t;

typedef struct mouse {
  f32_t x, y;
  f32_t dx, dy;

  btn_t btns[mouse_btn_count];
} mouse_t;

typedef struct kbd {
  key_t keys[kbd_key_count];
} kbd_t;

typedef struct gamepad {
  f32_t lx, ly;
  f32_t rx, ry;
  f32_t l2, r2;

  btn_t btns[gamepad_btn_count];
} gamepad_t;

typedef struct input {
  mouse_t mouse;
  kbd_t kbd;
  gamepad_t gamepad[4];
} input_t;
