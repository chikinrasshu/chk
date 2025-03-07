#include "win_base.h"

size_t win_input_mouse_from_impl(u32_t impl_id) {
  size_t result = mouse_btn_unknown;

  switch (impl_id) {
  case GLFW_MOUSE_BUTTON_1:
    result = mouse_btn_1;
    break;
  case GLFW_MOUSE_BUTTON_2:
    result = mouse_btn_2;
    break;
  case GLFW_MOUSE_BUTTON_3:
    result = mouse_btn_3;
    break;
  case GLFW_MOUSE_BUTTON_4:
    result = mouse_btn_4;
    break;
  case GLFW_MOUSE_BUTTON_5:
    result = mouse_btn_5;
    break;
  case GLFW_MOUSE_BUTTON_6:
    result = mouse_btn_6;
    break;
  case GLFW_MOUSE_BUTTON_7:
    result = mouse_btn_7;
    break;
  case GLFW_MOUSE_BUTTON_8:
    result = mouse_btn_8;
    break;
  }

  return result;
}

size_t win_input_kbd_from_impl(u32_t impl_id) {
  size_t result = kbd_key_unknown;

  switch (impl_id) {
  case GLFW_KEY_SPACE:;
    result = kbd_key_space;
    break;
  case GLFW_KEY_APOSTROPHE:;
    result = kbd_key_apostrophe;
    break;
  case GLFW_KEY_COMMA:;
    result = kbd_key_comma;
    break;
  case GLFW_KEY_MINUS:;
    result = kbd_key_minus;
    break;
  case GLFW_KEY_PERIOD:;
    result = kbd_key_period;
    break;
  case GLFW_KEY_SLASH:;
    result = kbd_key_slash;
    break;
  case GLFW_KEY_0:;
    result = kbd_key_0;
    break;
  case GLFW_KEY_1:;
    result = kbd_key_1;
    break;
  case GLFW_KEY_2:;
    result = kbd_key_2;
    break;
  case GLFW_KEY_3:;
    result = kbd_key_3;
    break;
  case GLFW_KEY_4:;
    result = kbd_key_4;
    break;
  case GLFW_KEY_5:;
    result = kbd_key_5;
    break;
  case GLFW_KEY_6:;
    result = kbd_key_6;
    break;
  case GLFW_KEY_7:;
    result = kbd_key_7;
    break;
  case GLFW_KEY_8:;
    result = kbd_key_8;
    break;
  case GLFW_KEY_9:;
    result = kbd_key_9;
    break;
  case GLFW_KEY_SEMICOLON:;
    result = kbd_key_semicolon;
    break;
  case GLFW_KEY_EQUAL:;
    result = kbd_key_equal;
    break;
  case GLFW_KEY_A:;
    result = kbd_key_A;
    break;
  case GLFW_KEY_B:;
    result = kbd_key_B;
    break;
  case GLFW_KEY_C:;
    result = kbd_key_C;
    break;
  case GLFW_KEY_D:;
    result = kbd_key_D;
    break;
  case GLFW_KEY_E:;
    result = kbd_key_E;
    break;
  case GLFW_KEY_F:;
    result = kbd_key_F;
    break;
  case GLFW_KEY_G:;
    result = kbd_key_G;
    break;
  case GLFW_KEY_H:;
    result = kbd_key_H;
    break;
  case GLFW_KEY_I:;
    result = kbd_key_I;
    break;
  case GLFW_KEY_J:;
    result = kbd_key_J;
    break;
  case GLFW_KEY_K:;
    result = kbd_key_K;
    break;
  case GLFW_KEY_L:;
    result = kbd_key_L;
    break;
  case GLFW_KEY_M:;
    result = kbd_key_M;
    break;
  case GLFW_KEY_N:;
    result = kbd_key_N;
    break;
  case GLFW_KEY_O:;
    result = kbd_key_O;
    break;
  case GLFW_KEY_P:;
    result = kbd_key_P;
    break;
  case GLFW_KEY_Q:;
    result = kbd_key_Q;
    break;
  case GLFW_KEY_R:;
    result = kbd_key_R;
    break;
  case GLFW_KEY_S:;
    result = kbd_key_S;
    break;
  case GLFW_KEY_T:;
    result = kbd_key_T;
    break;
  case GLFW_KEY_U:;
    result = kbd_key_U;
    break;
  case GLFW_KEY_V:;
    result = kbd_key_V;
    break;
  case GLFW_KEY_W:;
    result = kbd_key_W;
    break;
  case GLFW_KEY_X:;
    result = kbd_key_X;
    break;
  case GLFW_KEY_Y:;
    result = kbd_key_Y;
    break;
  case GLFW_KEY_Z:;
    result = kbd_key_Z;
    break;
  case GLFW_KEY_LEFT_BRACKET:;
    result = kbd_key_left_bracket;
    break;
  case GLFW_KEY_BACKSLASH:;
    result = kbd_key_backslash;
    break;
  case GLFW_KEY_RIGHT_BRACKET:;
    result = kbd_key_right_bracket;
    break;
  case GLFW_KEY_GRAVE_ACCENT:;
    result = kbd_key_grave_accent;
    break;
  case GLFW_KEY_ESCAPE:;
    result = kbd_key_escape;
    break;
  case GLFW_KEY_ENTER:;
    result = kbd_key_enter;
    break;
  case GLFW_KEY_TAB:;
    result = kbd_key_tab;
    break;
  case GLFW_KEY_BACKSPACE:;
    result = kbd_key_backspace;
    break;
  case GLFW_KEY_INSERT:;
    result = kbd_key_insert;
    break;
  case GLFW_KEY_DELETE:;
    result = kbd_key_delete;
    break;
  case GLFW_KEY_RIGHT:;
    result = kbd_key_right;
    break;
  case GLFW_KEY_LEFT:;
    result = kbd_key_left;
    break;
  case GLFW_KEY_DOWN:;
    result = kbd_key_down;
    break;
  case GLFW_KEY_UP:;
    result = kbd_key_up;
    break;
  case GLFW_KEY_PAGE_UP:;
    result = kbd_key_page_up;
    break;
  case GLFW_KEY_PAGE_DOWN:;
    result = kbd_key_page_down;
    break;
  case GLFW_KEY_HOME:;
    result = kbd_key_home;
    break;
  case GLFW_KEY_END:;
    result = kbd_key_end;
    break;
  case GLFW_KEY_CAPS_LOCK:;
    result = kbd_key_caps_lock;
    break;
  case GLFW_KEY_SCROLL_LOCK:;
    result = kbd_key_scroll_lock;
    break;
  case GLFW_KEY_NUM_LOCK:;
    result = kbd_key_num_lock;
    break;
  case GLFW_KEY_PRINT_SCREEN:;
    result = kbd_key_print_screen;
    break;
  case GLFW_KEY_PAUSE:;
    result = kbd_key_pause;
    break;
  case GLFW_KEY_F1:;
    result = kbd_key_F1;
    break;
  case GLFW_KEY_F2:;
    result = kbd_key_F2;
    break;
  case GLFW_KEY_F3:;
    result = kbd_key_F3;
    break;
  case GLFW_KEY_F4:;
    result = kbd_key_F4;
    break;
  case GLFW_KEY_F5:;
    result = kbd_key_F5;
    break;
  case GLFW_KEY_F6:;
    result = kbd_key_F6;
    break;
  case GLFW_KEY_F7:;
    result = kbd_key_F7;
    break;
  case GLFW_KEY_F8:;
    result = kbd_key_F8;
    break;
  case GLFW_KEY_F9:;
    result = kbd_key_F9;
    break;
  case GLFW_KEY_F10:;
    result = kbd_key_F10;
    break;
  case GLFW_KEY_F11:;
    result = kbd_key_F11;
    break;
  case GLFW_KEY_F12:;
    result = kbd_key_F12;
    break;
  case GLFW_KEY_F13:;
    result = kbd_key_F13;
    break;
  case GLFW_KEY_F14:;
    result = kbd_key_F14;
    break;
  case GLFW_KEY_F15:;
    result = kbd_key_F15;
    break;
  case GLFW_KEY_F16:;
    result = kbd_key_F16;
    break;
  case GLFW_KEY_F17:;
    result = kbd_key_F17;
    break;
  case GLFW_KEY_F18:;
    result = kbd_key_F18;
    break;
  case GLFW_KEY_F19:;
    result = kbd_key_F19;
    break;
  case GLFW_KEY_F20:;
    result = kbd_key_F20;
    break;
  case GLFW_KEY_F21:;
    result = kbd_key_F21;
    break;
  case GLFW_KEY_F22:;
    result = kbd_key_F22;
    break;
  case GLFW_KEY_F23:;
    result = kbd_key_F23;
    break;
  case GLFW_KEY_F24:;
    result = kbd_key_F24;
    break;
  case GLFW_KEY_F25:;
    result = kbd_key_F25;
    break;
  case GLFW_KEY_KP_0:;
    result = kbd_key_keypad_0;
    break;
  case GLFW_KEY_KP_1:;
    result = kbd_key_keypad_1;
    break;
  case GLFW_KEY_KP_2:;
    result = kbd_key_keypad_2;
    break;
  case GLFW_KEY_KP_3:;
    result = kbd_key_keypad_3;
    break;
  case GLFW_KEY_KP_4:;
    result = kbd_key_keypad_4;
    break;
  case GLFW_KEY_KP_5:;
    result = kbd_key_keypad_5;
    break;
  case GLFW_KEY_KP_6:;
    result = kbd_key_keypad_6;
    break;
  case GLFW_KEY_KP_7:;
    result = kbd_key_keypad_7;
    break;
  case GLFW_KEY_KP_8:;
    result = kbd_key_keypad_8;
    break;
  case GLFW_KEY_KP_9:;
    result = kbd_key_keypad_9;
    break;
  case GLFW_KEY_KP_DECIMAL:;
    result = kbd_key_keypad_decimal;
    break;
  case GLFW_KEY_KP_DIVIDE:;
    result = kbd_key_keypad_divide;
    break;
  case GLFW_KEY_KP_MULTIPLY:;
    result = kbd_key_keypad_multiply;
    break;
  case GLFW_KEY_KP_SUBTRACT:;
    result = kbd_key_keypad_subtract;
    break;
  case GLFW_KEY_KP_ADD:;
    result = kbd_key_keypad_add;
    break;
  case GLFW_KEY_KP_ENTER:;
    result = kbd_key_keypad_enter;
    break;
  case GLFW_KEY_KP_EQUAL:;
    result = kbd_key_keypad_equal;
    break;
  case GLFW_KEY_LEFT_SHIFT:;
    result = kbd_key_left_shift;
    break;
  case GLFW_KEY_LEFT_CONTROL:;
    result = kbd_key_left_control;
    break;
  case GLFW_KEY_LEFT_ALT:;
    result = kbd_key_left_alt;
    break;
  case GLFW_KEY_LEFT_SUPER:;
    result = kbd_key_left_super;
    break;
  case GLFW_KEY_RIGHT_SHIFT:;
    result = kbd_key_right_shift;
    break;
  case GLFW_KEY_RIGHT_CONTROL:;
    result = kbd_key_right_control;
    break;
  case GLFW_KEY_RIGHT_ALT:;
    result = kbd_key_right_alt;
    break;
  case GLFW_KEY_RIGHT_SUPER:;
    result = kbd_key_right_super;
    break;
  case GLFW_KEY_MENU:;
    result = kbd_key_menu;
    break;
  }

  return result;
}

size_t win_input_gamepad_from_impl(u32_t impl_id) {
  size_t result = gamepad_btn_unknown;

  switch (impl_id) {
  case GLFW_GAMEPAD_BUTTON_DPAD_UP:
    result = gamepad_btn_dpad_up;
    break;
  case GLFW_GAMEPAD_BUTTON_DPAD_DOWN:
    result = gamepad_btn_dpad_down;
    break;
  case GLFW_GAMEPAD_BUTTON_DPAD_LEFT:
    result = gamepad_btn_dpad_left;
    break;
  case GLFW_GAMEPAD_BUTTON_DPAD_RIGHT:
    result = gamepad_btn_dpad_right;
    break;
  case GLFW_GAMEPAD_BUTTON_A:
    result = gamepad_btn_A;
    break;
  case GLFW_GAMEPAD_BUTTON_B:
    result = gamepad_btn_B;
    break;
  case GLFW_GAMEPAD_BUTTON_X:
    result = gamepad_btn_X;
    break;
  case GLFW_GAMEPAD_BUTTON_Y:
    result = gamepad_btn_Y;
    break;
  case GLFW_GAMEPAD_BUTTON_LEFT_BUMPER:
    result = gamepad_btn_left_bumper;
    break;
  case GLFW_GAMEPAD_BUTTON_LEFT_THUMB:
    result = gamepad_btn_left_thumb;
    break;
  case GLFW_GAMEPAD_BUTTON_RIGHT_BUMPER:
    result = gamepad_btn_right_bumper;
    break;
  case GLFW_GAMEPAD_BUTTON_RIGHT_THUMB:
    result = gamepad_btn_right_thumb;
    break;
  case GLFW_GAMEPAD_BUTTON_BACK:
    result = gamepad_btn_back;
    break;
  case GLFW_GAMEPAD_BUTTON_START:
    result = gamepad_btn_start;
    break;
  case GLFW_GAMEPAD_BUTTON_GUIDE:
    result = gamepad_btn_guide;
    break;
  }

  return result;
}
