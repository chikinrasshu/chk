add_library(chk_renderer)
add_library(chk::renderer ALIAS chk_renderer)

target_sources(chk_renderer
  PUBLIC FILE_SET chk_win_hdrs TYPE HEADERS BASE_DIRS "include" FILES
    "include/chk/renderer.h"
  PRIVATE
    "src/renderer.c"
)

target_link_libraries(chk_renderer 
  PUBLIC chk::core 
  PRIVATE glad::gl
)
