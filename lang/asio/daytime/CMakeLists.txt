project(daytime)

add_executable(resolver resolver.cpp)

target_include_directories(resolver PRIVATE /usr/include/)
target_link_libraries(resolver PRIVATE pthread)
