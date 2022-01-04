project(daytime)

add_executable(resolver resolver.cpp)
add_executable(daytime_client daytime_client.cpp)
add_executable(daytime_server daytime_server.cpp)

target_include_directories(resolver PRIVATE /usr/include/)
target_link_libraries(resolver PRIVATE pthread)
target_link_libraries(daytime_client PRIVATE pthread)
target_link_libraries(daytime_server PRIVATE pthread)
