#include <chk/launcher.h>

int main() {
  s32_t result = 1;

  launcher_t l;
  if (launcher_create(&l)) {

    result = launcher_run(&l, NULL, NULL);

    launcher_destroy(&l);
  } else {
    log_error("failed to create the launcher");
  }

  return result;
}
