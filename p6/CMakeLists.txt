cmake_minimum_required(VERSION 3.10)
project(TestApp)

# Set build type to Debug
set(CMAKE_BUILD_TYPE Debug)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directories
include_directories(include)

# Add executable target
add_executable(test "src/Source.cpp")

# Link libraries
target_link_libraries(test ${CMAKE_SOURCE_DIR}/lib/libShape.a)
