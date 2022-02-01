cmake_minimum_required(VERSION 3.21)

project(simple)
find_package(sdbus-c++ REQUIRED)

add_executable(server server.cpp)
target_link_libraries(server PRIVATE SDBusCpp::sdbus-c++)

add_executable(client client.cpp)
target_link_libraries(client PRIVATE SDBusCpp::sdbus-c++)


find_package(PkgConfig)

pkg_check_modules(
        Systemd REQUIRED
        IMPORTED_TARGET
        libsystemd)


add_executable(client2 client2.cpp)
target_link_libraries(client2 PRIVATE PkgConfig::Systemd)

add_executable(client3 client3.cpp)
target_link_libraries(client3 PRIVATE PkgConfig::Systemd)

add_executable(client4 client4.cpp)
target_link_libraries(client4 PRIVATE PkgConfig::Systemd)
