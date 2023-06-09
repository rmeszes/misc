# CMakeList.txt : CMake project for misc, include source and define
# project specific logic here.
#
cmake_minimum_required(VERSION 3.12)

project(misc)

# Add source to this project's executable. 
add_executable (misc "misc.cpp"
					"misc.h"
					"gtest_lite.h"
					"memtrace.h"
					"memtrace.cpp"
					"min_heap.h"
        "array.hpp")




add_compile_definitions(MEMTRACE)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET misc PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.