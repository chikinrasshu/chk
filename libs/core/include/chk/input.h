#pragma once

#include <chk/types.h>

typedef enum mouse_btn {
  mouse_btn_unknown = 0,

  mouse_btn_1,
  mouse_btn_2,
  mouse_btn_3,
  mouse_btn_4,
  mouse_btn_5,
  mouse_btn_6,
  mouse_btn_7,
  mouse_btn_8,

  mouse_btn_count,

  mouse_btn_left = mouse_btn_1,
  mouse_btn_right = mouse_btn_2,
  mouse_btn_middle = mouse_btn_3,
  mouse_btn_up = mouse_btn_4,
  mouse_btn_down = mouse_btn_5,
} mouse_btn_t;

typedef enum kbd_key {
  kbd_key_unknown = 0,

  kbd_key_space = 32,
  kbd_key_apostrophe = 39,
  kbd_key_comma = 44,
  kbd_key_minus = 45,
  kbd_key_period = 46,
  kbd_key_slash = 47,
  kbd_key_0 = 48,
  kbd_key_1 = 49,
  kbd_key_2 = 50,
  kbd_key_3 = 51,
  kbd_key_4 = 52,
  kbd_key_5 = 53,
  kbd_key_6 = 54,
  kbd_key_7 = 55,
  kbd_key_8 = 56,
  kbd_key_9 = 57,
  kbd_key_semicolon = 59,
  kbd_key_equal = 61,
  kbd_key_A = 65,
  kbd_key_B = 66,
  kbd_key_C = 67,
  kbd_key_D = 68,
  kbd_key_E = 69,
  kbd_key_F = 70,
  kbd_key_G = 71,
  kbd_key_H = 72,
  kbd_key_I = 73,
  kbd_key_J = 74,
  kbd_key_K = 75,
  kbd_key_L = 76,
  kbd_key_M = 77,
  kbd_key_N = 78,
  kbd_key_O = 79,
  kbd_key_P = 80,
  kbd_key_Q = 81,
  kbd_key_R = 82,
  kbd_key_S = 83,
  kbd_key_T = 84,
  kbd_key_U = 85,
  kbd_key_V = 86,
  kbd_key_W = 87,
  kbd_key_X = 88,
  kbd_key_Y = 89,
  kbd_key_Z = 90,
  kbd_key_left_bracket = 91,
  kbd_key_backslash = 92,
  kbd_key_right_bracket = 93,
  kbd_key_grave_accent = 96,

  /* Function keys */
  kbd_key_escape = 256,
  kbd_key_enter = 257,
  kbd_key_tab = 258,
  kbd_key_backspace = 259,
  kbd_key_insert = 260,
  kbd_key_delete = 261,
  kbd_key_right = 262,
  kbd_key_left = 263,
  kbd_key_down = 264,
  kbd_key_up = 265,
  kbd_key_page_up = 266,
  kbd_key_page_down = 267,
  kbd_key_home = 268,
  kbd_key_end = 269,
  kbd_key_caps_lock = 280,
  kbd_key_scroll_lock = 281,
  kbd_key_num_lock = 282,
  kbd_key_print_screen = 283,
  kbd_key_pause = 284,
  kbd_key_F1 = 290,
  kbd_key_F2 = 291,
  kbd_key_F3 = 292,
  kbd_key_F4 = 293,
  kbd_key_F5 = 294,
  kbd_key_F6 = 295,
  kbd_key_F7 = 296,
  kbd_key_F8 = 297,
  kbd_key_F9 = 298,
  kbd_key_F10 = 299,
  kbd_key_F11 = 300,
  kbd_key_F12 = 301,
  kbd_key_F13 = 302,
  kbd_key_F14 = 303,
  kbd_key_F15 = 304,
  kbd_key_F16 = 305,
  kbd_key_F17 = 306,
  kbd_key_F18 = 307,
  kbd_key_F19 = 308,
  kbd_key_F20 = 309,
  kbd_key_F21 = 310,
  kbd_key_F22 = 311,
  kbd_key_F23 = 312,
  kbd_key_F24 = 313,
  kbd_key_F25 = 314,
  kbd_key_keypad_0 = 320,
  kbd_key_keypad_1 = 321,
  kbd_key_keypad_2 = 322,
  kbd_key_keypad_3 = 323,
  kbd_key_keypad_4 = 324,
  kbd_key_keypad_5 = 325,
  kbd_key_keypad_6 = 326,
  kbd_key_keypad_7 = 327,
  kbd_key_keypad_8 = 328,
  kbd_key_keypad_9 = 329,
  kbd_key_keypad_decimal = 330,
  kbd_key_keypad_divide = 331,
  kbd_key_keypad_multiply = 332,
  kbd_key_keypad_subtract = 333,
  kbd_key_keypad_add = 334,
  kbd_key_keypad_enter = 335,
  kbd_key_keypad_equal = 336,
  kbd_key_left_shift = 340,
  kbd_key_left_control = 341,
  kbd_key_left_alt = 342,
  kbd_key_left_super = 343,
  kbd_key_right_shift = 344,
  kbd_key_right_control = 345,
  kbd_key_right_alt = 346,
  kbd_key_right_super = 347,
  kbd_key_menu = 348,

  kbd_key_count,
} kbd_key_t;

typedef enum gamepad_btn {
  gamepad_btn_unknown = 0,

  gamepad_btn_A,
  gamepad_btn_B,
  gamepad_btn_X,
  gamepad_btn_Y,
  gamepad_btn_left_bumper,
  gamepad_btn_right_bumper,
  gamepad_btn_left_trigger,
  gamepad_btn_right_trigger,
  gamepad_btn_back,
  gamepad_btn_start,
  gamepad_btn_guide,
  gamepad_btn_left_thumb,
  gamepad_btn_right_thumb,
  gamepad_btn_dpad_up,
  gamepad_btn_dpad_right,
  gamepad_btn_dpad_down,
  gamepad_btn_dpad_left,

  gamepad_btn_count,

  gamepad_btn_L1 = gamepad_btn_left_bumper,
  gamepad_btn_L2 = gamepad_btn_left_trigger,
  gamepad_btn_L3 = gamepad_btn_left_thumb,
  gamepad_btn_R1 = gamepad_btn_right_bumper,
  gamepad_btn_R2 = gamepad_btn_right_trigger,
  gamepad_btn_R3 = gamepad_btn_right_thumb,

  gamepad_btn_select = gamepad_btn_back,
  gamepad_btn_share = gamepad_btn_back,
  gamepad_btn_options = gamepad_btn_start,
  gamepad_btn_ps = gamepad_btn_guide,

  gamepad_btn_cross = gamepad_btn_A,
  gamepad_btn_circle = gamepad_btn_B,
  gamepad_btn_square = gamepad_btn_X,
  gamepad_btn_triangle = gamepad_btn_Y,
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
