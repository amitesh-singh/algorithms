project(basic)

add_executable(crash crash.cpp)
add_executable(basic basic.cpp)
target_include_directories(crash PRIVATE /usr/include/)
target_link_libraries(crash PRIVATE pthread)
