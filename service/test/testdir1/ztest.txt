cmake_minimum_required(VERSION 3.14)

set(CMAKE_TOOLCHAIN_FILE "vcpkg/scripts/buildsystems/vcpkg.cmake")

project(get_sorty VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)

# find_package(GTest CONFIG REQUIRED)
# enable_testing()

add_subdirectory(service)
add_subdirectory(interface)

# target_link_libraries(get_sorty PRIVATE GTest::gtest GTest::gtest_main)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)