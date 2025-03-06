add_library(chk_win)
add_library(chk::win ALIAS chk_win)

target_sources(chk_win
  PUBLIC FILE_SET chk_win_hdrs TYPE HEADERS BASE_DIRS "include" FILES
    "include/chk/win.h"
  PRIVATE
    "src/win_base.h"
    "src/win.c"
    "src/win_cb.c"
    "src/win_input.c"
)

target_link_libraries(chk_win 
  PUBLIC chk::core 
  PRIVATE glfw glad::gl
)
