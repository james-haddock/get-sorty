cmake_minimum_required(VERSION 3.14)
project(get_sorty VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)

# find_package(GTest CONFIG REQUIRED)
# enable_testing()

add_executable(get_sorty src/main.cpp)

# target_link_libraries(get_sorty PRIVATE GTest::gtest GTest::gtest_main)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)