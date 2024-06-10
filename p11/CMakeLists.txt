cmake_minimum_required(VERSION 3.0)
project(xml_parser)

# Create a subdirectory for TinyXML
add_subdirectory(external/tinyxml2)

# Include directories for TinyXML headers
include_directories(external/tinyxml2/include)

# Define the source file
set(SOURCE_FILE src/Source.cpp)

# Add the executable
add_executable(xml_parser ${SOURCE_FILE})

# Target the executable to link with TinyXML library
target_link_libraries(xml_parser tinyxml2)
