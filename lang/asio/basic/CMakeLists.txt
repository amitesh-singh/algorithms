project(basic)

add_executable(basic basic.cpp)
add_executable(basic_process keep_alive.cpp)
add_executable(keep_alive2 keep_alive2.cpp)
add_executable(keep_alive3 keep_alive3.cpp)

target_link_libraries(basic PRIVATE pthread)
target_link_libraries(basic_process PRIVATE pthread)
target_link_libraries(keep_alive2 PRIVATE pthread)
target_link_libraries(keep_alive3 PRIVATE pthread)
