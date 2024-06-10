cmake_minimum_required(VERSION 3.0)
project(xml_parser)

# Create a subdirectory for TinyXML (assuming it's pre-built for 32-bit)
add_subdirectory(external/tinyxml2)

# Include directories for TinyXML headers
include_directories(external/tinyxml2/include)

# Define the source file
set(SOURCE_FILE src/Source.cpp)

# Option 1: Using the -m32 flag (if your generator supports it)
# if(CMAKE_GENERATOR MATCHES "Unix Makefiles")
#   set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -m32")
#   set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -m32")
# endif()

# Option 2: Using a Toolchain File (more portable)
# Create a file named 32bitToolchain.cmake in your project directory:

# 32bitToolchain.cmake
SET(CMAKE_C_FLAGS "-m32")
SET(CMAKE_CXX_FLAGS "-m32")
SET(CMAKE_LINKER_FLAGS "-m32")

# Then, configure with the toolchain file:
# cmake -DCMAKE_TOOLCHAIN_FILE=32bitToolchain.cmake your_project_directory

# Add the executable
add_executable(xml_parser ${SOURCE_FILE})

# Target the executable to link with TinyXML library
target_link_libraries(xml_parser tinyxml2)