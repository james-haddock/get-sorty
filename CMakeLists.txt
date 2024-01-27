cmake_minimum_required(VERSION 3.12)
cmake_policy(SET CMP0048 NEW)

include_directories(vcpkg_installed/arm64-osx/include)

project(get-sorty VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(service)
add_subdirectory(interface)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

find_package(boost CONFIG REQUIRED)

add_executable(main launcher.cpp)

target_include_directories(main PRIVATE include)

target_link_libraries(main PRIVATE ${Boost_LIBRARIES})