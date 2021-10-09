cmake_minimum_required(VERSION 3.21)

project(cpu)

find_package(sdbus-c++ REQUIRED)

# issued of make hello
add_custom_target(hello
COMMAND echo "Hello"
COMMENT "Just a Hi.")

add_custom_target(header
COMMAND sdbus-c++-xml2cpp cpu.xml --adaptor=server-intf.h --proxy=client-intf.h
COMMENT "Header files are generated for client and server.")

add_executable(server server.cpp)
target_link_libraries(server PRIVATE SDBusCpp::sdbus-c++)

add_executable(client client.cpp)
target_link_libraries(client PRIVATE SDBusCpp::sdbus-c++)
