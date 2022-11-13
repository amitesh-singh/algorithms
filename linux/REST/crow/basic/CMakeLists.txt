project("crow example")
find_package(Crow)
add_executable(hello_world main.cpp)
target_link_libraries(hello_world PUBLIC Crow::Crow)
