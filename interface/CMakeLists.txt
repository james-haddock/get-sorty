include_directories(include)

add_executable(interface src/cli.cpp)


find_package(ftxui CONFIG REQUIRED)

find_package(Boost REQUIRED COMPONENTS system)
target_link_libraries(interface PRIVATE ftxui::dom ftxui::screen ftxui::component Boost::boost Boost::system)