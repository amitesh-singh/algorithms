project(sdbus basic)
find_package(systemd REQUIRED)
add_executable(sample_client main.cpp)
target_link_libraries(sample_client Systemd::Systemd)