find_package(ftxui CONFIG REQUIRED)
find_package(boost CONFIG REQUIRED interprocess)

add_executable(interface src/cli.cpp)

target_include_directories(interface PRIVATE include)

target_link_libraries(interface PRIVATE ${Boost_LIBRARIES} ftxui::dom ftxui::component ftxui::screen)