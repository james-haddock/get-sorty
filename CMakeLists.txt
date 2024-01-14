cmake_minimum_required(VERSION 3.10)

set(CMAKE_TOOLCHAIN_FILE /vcpkg/scripts/buildsystems/vcpkg.cmake)

project(get_sorty VERSION 0.1)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

file(GLOB SOURCES "*.cpp")

add_executable(get_sorty ${SOURCES})

configure_file(Config.h.in Config.h)

target_include_directories(get_sorty PUBLIC "${PROJECT_BINARY_DIR}")