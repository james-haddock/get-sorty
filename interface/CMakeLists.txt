set(VCPKG_TARGET_TRIPLET arm64-osx)

add_executable(interface src/cli.cpp)

target_include_directories(interface PRIVATE include)

find_package(ftxui CONFIG REQUIRED)

find_package(Boost REQUIRED system)
target_link_libraries(interface PRIVATE ftxui::dom ftxui::screen ftxui::component Boost::boost Boost::system)