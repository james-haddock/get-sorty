// #ifdef __unix__
#include <unistd.h>
// #endif
#include <boost/interprocess/shared_memory_object.hpp>
#include <boost/interprocess/mapped_region.hpp>
#include <ftxui/component/component.hpp> 
#include <ftxui/component/screen_interactive.hpp>
#include <boost/asio.hpp>
#include <chrono>
#include <filesystem>
#include <iostream>
#include <set>
#include <thread>
#include <vector>
#include "infrastructure/directory_monitor.h"
#include <signal.h>

using namespace ftxui;
using boost::asio::local::stream_protocol;

int main() {

      struct shm_remove
      {
         shm_remove() { boost::interprocess::shared_memory_object::remove("GSSharedMemory"); }
         ~shm_remove(){ boost::interprocess::shared_memory_object::remove("GSSharedMemory"); }
      } remover;
    
    boost::interprocess::shared_memory_object shm;

        shm = boost::interprocess::shared_memory_object(
            boost::interprocess::create_only,
            "GSSharedMemory",
            boost::interprocess::read_write
        );
        shm.truncate(sizeof(int));

    boost::interprocess::mapped_region region(shm, boost::interprocess::read_write);

    void * addr = region.get_address();

    int * command = static_cast<int*>(addr);

    std::cout << "Get Sorty!\n";
    std::vector<std::filesystem::path> directory_paths_to_monitor;
    // retrieve directories to monitor from get_sorty_config.TOML
    directory_paths_to_monitor = {"/Users/jameshaddock/Desktop/Coding/Projects/get_sorty/service/test/testdir1"};
    // check integrity of the file paths that have been stored
    DirectoryMonitor directoryMonitor(directory_paths_to_monitor);
    *command = 1;
    do {
        if (*command == 0) {
            directoryMonitor.start_monitoring();
            std::cout << "Service started\n";
            *command = -1;
        } else if (*command == 1) {
            directoryMonitor.stop_monitoring();
            std::cout << "Service stopped\n";
            *command = -1;
        }
        std::this_thread::sleep_for(std::chrono::seconds(1));
    } while (true);

  std::cout << "fin\n";
  return 0;
}