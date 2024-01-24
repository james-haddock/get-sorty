cmake_minimum_required(VERSION 3.14)

set(VCPKG_TARGET_TRIPLET arm64-osx)

set(CMAKE_TOOLCHAIN_FILE "vcpkg/scripts/buildsystems/vcpkg.cmake")


project(get-sorty VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(service)
add_subdirectory(interface)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

