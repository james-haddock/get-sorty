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
    bool stop_observing = false;
    DirectoryMonitor directoryMonitor(file_paths);
    directoryMonitor.start_monitoring(stop_observing);

    std::string command;
    while (command != "stop") {
        std::cout << "Type 'stop' to stop monitoring and exit the program: ";
        std::cin >> command;
    }

    return 0;
};