cmake_minimum_required(VERSION 3.25)
project(oci_example)

include_directories(external/oracle/instantclient_23_4/sdk/include/)
link_directories(external/oracle/instantclient_23_4/)

add_executable(oci_example src/main.cpp)

target_link_libraries(oci_example 
occi
clntsh
)