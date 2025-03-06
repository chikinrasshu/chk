add_executable(chk_launcher)

target_sources(chk_launcher
  PUBLIC FILE_SET chk_launcher_hdrs TYPE HEADERS BASE_DIRS "include" FILES
    "include/chk/launcher.h"
  PRIVATE
    "src/launcher.c"
)

target_link_libraries(chk_launcher 
  PUBLIC chk::core
)
