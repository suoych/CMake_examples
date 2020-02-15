# set minimum cmake version
cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

# project name and language
project(hello_world_lib LANGUAGES CXX VERSION 1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# should we use our own math functions
option(USE_HELLO "Use tutorial provided hello world function" ON)

# configure a header file to pass some of the CMake settings
# to the source code
configure_file(hello_world_conf.h.in hello_world_conf.h)

# add the MathFunctions library
if(USE_HELLO)
  add_subdirectory(hello_world)
  list(APPEND EXTRA_LIBS hello_world)
  list(APPEND EXTRA_INCLUDES "${PROJECT_SOURCE_DIR}/hello_world")
endif()

# add the executable
add_executable(hello_world_1 main.cc)

target_link_libraries(hello_world_1 PUBLIC ${EXTRA_LIBS})

# add the binary tree to the search path for include files
# so that we will find hello_world.h
target_include_directories(hello_world_1 PUBLIC
	                   ${PROJECT_BINARY_DIR} 
	                   ${EXTRA_INCLUDES})

# add the install targets
install(TARGETS hello_world_1 DESTINATION bin)
install(FILES "${PROJECT_BINARY_DIR}/hello_world_conf.h"
  DESTINATION include
  )
install(EXPORT hello_world_targets
  FILE hello_world_targets.cmake
  DESTINATION lib/cmake/hello_world
  )

# enable testing
enable_testing()

# does the application run
add_test(NAME Runs COMMAND hello_world_1)

# define a function to simplify adding tests
function(do_test target result)
  add_test(NAME Comp COMMAND ${target} )
  set_tests_properties(Comp
    PROPERTIES PASS_REGULAR_EXPRESSION ${result}
    )
endfunction(do_test)

# do a bunch of result based tests
do_test(hello_world_1 "Hello, CMake world!")
