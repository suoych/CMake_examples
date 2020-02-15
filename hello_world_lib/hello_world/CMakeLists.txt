add_library(hello_world hello_world.cpp)
# add_library(hello_world SHARED hello_world.cpp) 
# using SHARED means dynamic library

# state that anybody linking to us needs to
# include the current source dir
# to find MathFunctions.h, while we don't.
target_include_directories(hello_world
          INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
          $<INSTALL_INTERFACE:include>
          )

# install rules
install(TARGETS hello_world DESTINATION lib EXPORT hello_world_targets)
install(FILES hello_world.h DESTINATION include)

