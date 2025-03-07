add_executable(chk_launcher)

target_sources(chk_launcher
  PUBLIC FILE_SET chk_launcher_hdrs TYPE HEADERS BASE_DIRS "include" FILES
    "include/chk/launcher.h"
  PRIVATE
    "src/launcher.c"
    "src/main.c"
)

target_link_libraries(chk_launcher 
  PUBLIC chk::core chk::win chk::renderer
)

add_custom_target(chk_launcher_copy_assets ALL)
add_custom_command(TARGET chk_launcher_copy_assets POST_BUILD
  COMMENT "Copying assets to ${PROJECT_SOURCE_DIR}/assets"
  COMMAND ${CMAKE_COMMAND} -E make_directory "./assets"
  COMMAND ${CMAKE_COMMAND} -E copy_directory_if_different 
    "${PROJECT_SOURCE_DIR}/assets" "./assets"
  WORKING_DIRECTORY "$<TARGET_FILE_DIR:chk_launcher>"
)
