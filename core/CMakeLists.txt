cmake_minimum_required(VERSION 3.30)
project(chk_core LANGUAGES C DESCRIPTION "chk core library" VERSION 0.1.0)

add_subdirectory("external")

add_library(chk_core)

target_sources(chk_core
  PUBLIC FILE_SET chk_core_hdrs TYPE HEADERS BASE_DIRS "include" FILES
    "include/chk/core.h"
    "include/chk/file.h"
    "include/chk/fmt.h"
    "include/chk/log.h"
    "include/chk/memory.h"
    "include/chk/types.h"
    "include/chk/util.h"
  PRIVATE
    "src/file.c"
    "src/fmt.c"
    "src/log.c"
    "src/memory.c"
    "src/util.c"
)

target_compile_features(chk_core PUBLIC c_std_11)

target_link_libraries(chk_core PRIVATE cwalk)
