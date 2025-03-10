cmake_minimum_required(VERSION 3.30)
project(chk LANGUAGES C DESCRIPTION "chk engine" VERSION 0.1.0)

add_definitions(-DLOG_BASEPATH="${CMAKE_CURRENT_SOURCE_DIR}")

add_subdirectory("core")
add_subdirectory("launcher")
#add_subdirectory("plugins")
