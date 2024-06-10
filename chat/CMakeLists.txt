cmake_minimum_required(VERSION 3.25.1)

Project(Sockets VERSION 1.0)

add_executable(server src/main.cpp)
add_executable(client src/client.cpp)