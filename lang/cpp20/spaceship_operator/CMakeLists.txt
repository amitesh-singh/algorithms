cmake_minimum_required(VERSION 3.24)
project("spaceship")
add_compile_options(-std=c++20)
add_executable(spaceship spaceship.cpp)
add_executable(user_defined user_defined.cpp)
