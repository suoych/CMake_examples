# set minimum cmake version
cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

# project name and language
project(hello_world LANGUAGES CXX VERSION 1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# configure a header file to pass some of the CMake settings
# to the source code
configure_file(hello_world.h.in hello_world.h)

# add the executable
add_executable(hello_world hello_world.cpp)

# add the binary tree to the search path for include files
# so that we will find hello_world.h
target_include_directories(hello_world PUBLIC
	                   "${PROJECT_BINARY_DIR}")


