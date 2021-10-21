cmake_minimum_required(VERSION 3.21)

project(addstrings)
find_package(sdbus-c++ REQUIRED)

# issue 'make header'
add_custom_target(header
    COMMAND sdbus-c++-xml2cpp db.xml --adaptor=server-intf.h --proxy=client.h
    COMMENT "Header files are generated for client and server.")

add_executable(server server.cpp)
target_link_libraries(server PRIVATE SDBusCpp::sdbus-c++)

add_executable(client client.cpp)
target_link_libraries(client PRIVATE SDBusCpp::sdbus-c++)
