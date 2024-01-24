include_directories(include)

add_executable(service src/service.cpp
 src/infrastructure/directory_monitor.cpp
 src/domain/process_new_file.cpp 
 src/domain/move_file.cpp 
 src/domain/file_lock.cpp
 src/config/user_config.cpp)

find_package(Boost REQUIRED COMPONENTS system)
target_link_libraries(service PRIVATE Boost::boost Boost::system)