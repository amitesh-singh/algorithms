project(basic)

add_executable(basic basic.cpp)
target_include_directories(basic PRIVATE /usr/include/)
target_link_libraries(basic PRIVATE pthread)
