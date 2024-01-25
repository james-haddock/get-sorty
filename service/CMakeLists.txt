set(VCPKG_TARGET_TRIPLET arm64-osx)

add_executable(service src/service.cpp
 src/infrastructure/directory_monitor.cpp
 src/domain/process_new_file.cpp 
 src/domain/move_file.cpp 
 src/domain/file_lock.cpp
 src/config/user_config.cpp)

 target_include_directories(service PRIVATE include)

find_package(Boost REQUIRED system)
target_link_libraries(service PRIVATE Boost::boost Boost::system)