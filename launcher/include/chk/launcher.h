#include <chk/core.h>

#include <chk/renderer.h>
#include <chk/win.h>

typedef struct launcher {
  win_t win;
  renderer_t renderer;

  win_callback_t *_on_frame;
  void *_user_ptr;
} launcher_t;

bool launcher_create(launcher_t *l);
bool launcher_destroy(launcher_t *l);

s32_t launcher_run(launcher_t *l, win_callback_t *on_frame, void *user_ptr);
