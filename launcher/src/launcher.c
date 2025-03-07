#include "chk/win.h"
#include <chk/launcher.h>

WIN_CALLBACK(on_frame) {
  win_t *win = user_ptr;

  if (win) {
    // Test the keyboard for the letter P
    if (win->input.kbd.keys[kbd_key_P].is_pressed) {
      log_info("Letter P pressed!");
    }
  }
}

int main() {
  s32_t result = 1;

  win_t win;
  if (win_create(&win, 800, 600, "chk_launcher")) {
    result = win_run(&win, on_frame, &win);
    win_destroy(&win);
  }

  return result;
}
