cmake_minimum_required(VERSION 3.10)

project(Shape)

file(GLOB SOURCES "src/*.cpp")
add_library(Shape SHARED ${SOURCES})

target_include_directories(Shape PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)