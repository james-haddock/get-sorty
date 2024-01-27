#include "infrastructure/directory_monitor.h"
#include <chrono>
#include <iostream>
#include <thread>

DirectoryMonitor::DirectoryMonitor(
    const std::vector<std::filesystem::path> &paths)
    : directories_to_monitor(paths) {}

DirectoryMonitor::~DirectoryMonitor() { stop_monitoring(); }

void DirectoryMonitor::initialize_files() {
    for (const auto &path : directories_to_monitor) {
        previous_files[path.string()] = get_files_in_directory(path);
    }
}

void DirectoryMonitor::start_monitoring() {
  initialize_files();
  stop_observing = false;
  monitor_thread = std::thread([&]() {
    while (!stop_observing) {
      std::cout << "Monitoring directories...\n";
      for (const auto &path : directories_to_monitor) {
        std::set<std::filesystem::path> current_files =
            get_files_in_directory(path);
        if (previous_files[path.string()] != current_files) {
          std::cout << "Directory " << path << " has changed.\n";
          std::vector<std::filesystem::path> new_files;
          for (const auto& file : current_files) {
            if (previous_files[path.string()].find(file) == previous_files[path.string()].end()) {
              new_files.push_back(file);
            }
          }
          for (const auto& file : new_files) {
            process_new_file.process_file(file);
          }
          previous_files[path.string()] = current_files;
        }
      }
      std::unique_lock<std::mutex> lk(cv_m);
      cv.wait_for(lk, std::chrono::seconds(5), [&] { return stop_observing; });
    }
  });
}

std::set<std::filesystem::path>
DirectoryMonitor::get_files_in_directory(const std::filesystem::path &path) {
  std::set<std::filesystem::path> files;

  for (const auto &entry : std::filesystem::directory_iterator(path)) {
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