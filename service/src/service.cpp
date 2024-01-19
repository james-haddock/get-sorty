#include "infrastructure/directory_monitor.h"
#include <chrono>
#include <filesystem>
#include <iostream>
#include <set>
#include <thread>
#include <vector>

int main() {
  std::vector<std::filesystem::path> file_paths;

      DirectoryMonitor directoryMonitor(file_paths);
      directoryMonitor.start_monitoring();
      std::string command;
      while (command != "stop") {
        std::cout << "Type 'stop' to stop monitoring and exit the program:\n";
        std::cin >> command;
      }
      directoryMonitor.stop_monitoring();
        std::cout << "The provided path is not a valid directory.\n";


  return 0;
};