project(basic)

add_executable(basic basic.cpp)
add_executable(basic_process keep_alive.cpp)
target_link_libraries(basic PRIVATE pthread)
target_link_libraries(basic_process PRIVATE pthread)
