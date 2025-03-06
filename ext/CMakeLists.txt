################################################################################
# cwalk - Cross platform path management                                       #
################################################################################

CPMAddPackage(NAME cwalk
  GITHUB_REPOSITORY likle/cwalk
  GIT_TAG v1.2.9
)


################################################################################
# glfw - Cross platform windowing library                                      #
################################################################################

CPMAddPackage(NAME glfw
  GITHUB_REPOSITORY glfw/glfw
  GIT_TAG 3.4
  OPTIONS
    "GLFW_BUILD_DOCS OFF"
    "GLFW_BUILD_EXAMPLES OFF"
    "GLFW_BUILD_TESTS OFF"
)


################################################################################
# glfw - Cross platform windowing library                                      #
################################################################################

CPMAddPackage(NAME glad
  GITHUB_REPOSITORY Dav1dde/glad
  GIT_TAG v2.0.8
  SOURCE_SUBDIR cmake
)

find_package(Python QUIET)
if (Python_FOUND)
  message(STATUS "Python was found")
  execute_process(COMMAND "${Python_EXECUTABLE}" "-c" "import jinja2"
    RESULT_VARIABLE res_code
  )
  if (NOT res_code OR res_code EQUAL 0)
    message(STATUS "jinja2 was found")
  else()
    message(FATAL_ERROR "glad2 OpenGL Generator requires the jinja2 python module to be installed")
  endif()
else()
  message(FATAL_ERROR "glad2 OpenGL Generator requires OpenGL to be installed")
endif()

glad_add_library(glad_gl QUIET REPRODUCIBLE API gl:core=4.1)
add_library(glad::gl ALIAS glad_gl)
