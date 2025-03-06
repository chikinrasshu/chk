cmake_minimum_required(VERSION 3.28)
project(chk_renderer)

################################################################################
# Settings and External dependencies                                           #
################################################################################

set(CMAKE_WARN_DEPRECATED OFF CACHE BOOL "")
include("cmake/CPM.cmake")

set(C_STANDARD 11)
set(C_STANDARD_REQUIRED TRUE)
set(C_EXTENSIONS FALSE)

add_compile_definitions(LOG_BASEDIR="${CMAKE_CURRENT_SOURCE_DIR}")

add_subdirectory("ext")


################################################################################
# Build the engine                                                             #
################################################################################

add_subdirectory("libs")
add_subdirectory("launcher")


################################################################################
# Build the plugins                                                            #
################################################################################

add_subdirectory("plugins")
