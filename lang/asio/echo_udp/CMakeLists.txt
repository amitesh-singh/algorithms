project(basic)

add_executable(basic sync_echo_server.cpp)
add_executable(async_echo_server async_echo.cpp)
add_executable(async_echo_server2 async_udp_echo_server.cpp)
add_executable(client client.cpp)

target_include_directories(basic PRIVATE /usr/include/)
target_link_libraries(basic PRIVATE pthread)
target_link_libraries(async_echo_server PRIVATE pthread)
target_link_libraries(async_echo_server2 PRIVATE pthread)
target_link_libraries(client PRIVATE pthread)
