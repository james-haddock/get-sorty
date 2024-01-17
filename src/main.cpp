#include <iostream>
#include <filesystem>
#include <set>
#include <thread>
#include <chrono>
#include <vector>
#include "infrastructure/directory_monitor.h"

// namespace fs = std::filesystem;

int main() {
    std::vector<std::filesystem::path> file_paths;
    std::string path;
    std::cout << "Please type your file path:";
    std::cin >> path;
    file_paths.push_back(path);
    DirectoryMonitor directoryMonitor(file_paths);
    directoryMonitor.start_monitoring();

    std::string command;
    while (command != "stop") {
        std::cout << "Type 'stop' to stop monitoring and exit the program:\n";
        std::cin >> command;
    }
    
    directoryMonitor.stop_monitoring();
    
    return 0;
};