add_library(chk_core)
add_library(chk::core ALIAS chk_core)

target_sources(chk_core
  PUBLIC FILE_SET chk_core_hdrs TYPE HEADERS BASE_DIRS "include" FILES
    "include/chk/core.h"
    "include/chk/fmt.h"
    "include/chk/input.h"
    "include/chk/log.h"
    "include/chk/types.h"
  PRIVATE
    "src/core.c"
    "src/fmt.c"
    "src/log.c"
)

target_link_libraries(chk_core PRIVATE cwalk)
