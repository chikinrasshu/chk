#include "chk/win.h"
#include <chk/launcher.h>

int main() {
  s32_t result = 1;

  win_t win;
  if (win_create(&win, 800, 600, "chk_launcher")) {
    result = win_run(&win, NULL, NULL);
    win_destroy(&win);
  }

  return result;
}
