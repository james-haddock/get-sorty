cmake_minimum_required(VERSION 3.14)
include_directories(include service/include interface/include)
include_directories(vcpkg_installed/arm64-osx/include)

set(VCPKG_TARGET_TRIPLET arm64-osx)

set(CMAKE_TOOLCHAIN_FILE "vcpkg/scripts/buildsystems/vcpkg.cmake")


project(get-sorty VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)

# add_executable(getsorty main.cpp)

add_subdirectory(service)
add_subdirectory(interface)

find_package(Boost REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

