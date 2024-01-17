#include <iostream>
#include <thread>
#include <chrono>
#include "infrastructure/directory_monitor.h"

DirectoryMonitor::DirectoryMonitor(const std::vector<std::filesystem::path>& paths) : directory_paths(paths) {}

DirectoryMonitor::~DirectoryMonitor() {
    stop_monitoring();
}

void DirectoryMonitor::start_monitoring() {
    stop_observing = false;
    monitor_thread = std::thread([&]() {
        while (!stop_observing) {
            std::cout << "Monitoring directories...\n";
            for (const auto& path : directory_paths) {
                std::set<std::filesystem::path> current_files = get_files_in_directory(path);
                if (previous_files[path.string()] != current_files) {
                    std::cout << "Directory " << path << " has changed.\n";
                    previous_files[path.string()] = current_files;
                }
            }
            std::unique_lock<std::mutex> lk(cv_m);
            cv.wait_for(lk, std::chrono::seconds(5), [&]{ return stop_observing; });
        }
    });
}

std::set<std::filesystem::path> DirectoryMonitor::get_files_in_directory(const std::filesystem::path& path) {
    std::set<std::filesystem::path> files;

    for (const auto& entry : std::filesystem::directory_iterator(path)) {
        if (entry.is_regular_file()) {
            files.insert(entry.path());
        }
    }

    return files;
}

void DirectoryMonitor::stop_monitoring() {
    stop_observing = true;
    cv.notify_one();
    if (monitor_thread.joinable()) {
        monitor_thread.join();
    }
}