project(addstrings)
find_package(sdbus-c++ REQUIRED)

add_executable(server server.cpp)
target_link_libraries(server PRIVATE SDBusCpp::sdbus-c++)

add_executable(client client.cpp)
target_link_libraries(client PRIVATE SDBusCpp::sdbus-c++)
