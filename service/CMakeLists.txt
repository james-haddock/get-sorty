add_executable(service src/service.cpp
 src/infrastructure/directory_monitor.cpp
 src/domain/process_new_file.cpp 
 src/domain/move_file.cpp 
 src/domain/file_lock.cpp
 src/config/user_config.cpp)

find_package(ftxui CONFIG REQUIRED)
find_package(boost CONFIG REQUIRED interprocess asio)

 target_include_directories(service PRIVATE include)

target_link_libraries(service PRIVATE ${Boost_LIBRARIES} ftxui::dom ftxui::component ftxui::screen)