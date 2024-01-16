#include <iostream>
#include <thread>
#include <chrono>
#include "infrastructure/directory_monitor.h"

DirectoryMonitor::DirectoryMonitor(const std::vector<std::filesystem::path>& paths) : directory_paths(paths) {}

DirectoryMonitor::~DirectoryMonitor() {
    if (monitor_thread.joinable()) {
        stop_monitoring();
    }
}

void DirectoryMonitor::start_monitoring(bool& stop_observing) {
    monitor_thread = std::thread([this](bool& stop_observing) {
        while (!stop_observing) {
            for (const auto& path : directory_paths) {
                std::set<std::filesystem::path> current_files = get_files_in_directory(path);
                if (previous_files[path.string()] != current_files) {
                    std::cout << "Directory " << path << " has changed.\n";
                    previous_files[path.string()] = current_files;
                }
            }
            std::this_thread::sleep_for(std::chrono::seconds(5));
        }
    });
}