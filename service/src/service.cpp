#include "infrastructure/directory_monitor.h"
#include <chrono>
#include <filesystem>
#include <iostream>
#include <set>
#include <thread>
#include <vector>

int main() {
  std::cout << "Get Sorty!\n";
  std::vector<std::filesystem::path> directory_paths_to_monitor;
  // retrieve directories to monitor from get_sorty_config.TOML
directory_paths_to_monitor = {"/Users/jameshaddock/Desktop/Coding/Projects/get_sorty/service/test/testdir1"};
// check integrity of the file paths that have been stored
      DirectoryMonitor directoryMonitor(directory_paths_to_monitor);
      directoryMonitor.start_monitoring();
      std::string command;
      while (command != "stop") {
        std::cout << "Type 'stop' to stop monitoring and exit the program:\n";
        std::cin >> command;
      }
      directoryMonitor.stop_monitoring();


  return 0;
};