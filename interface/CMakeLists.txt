include_directories(include)

add_executable(interface src/cli.cpp)


find_package(ftxui CONFIG REQUIRED)
target_link_libraries(interface PRIVATE ftxui::dom ftxui::screen ftxui::component)