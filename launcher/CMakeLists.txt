cmake_minimum_required(VERSION 3.30)
project(chk_launcher LANGUAGES C DESCRIPTION "chk launcher library" VERSION 0.1.0)

add_executable(chk_launcher)

target_sources(chk_launcher
  PUBLIC FILE_SET chk_launcher_hdrs TYPE HEADERS BASE_DIRS "include" FILES
    "include/chk/launcher.h"
  PRIVATE
    "src/launcher.c"
)

target_compile_features(chk_launcher PUBLIC c_std_11)

target_link_libraries(chk_launcher PUBLIC chk_core)
