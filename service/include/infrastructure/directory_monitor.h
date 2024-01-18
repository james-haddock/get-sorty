#include "domain/process_new_file.h"

#include <filesystem>
#include <map>
#include <set>
#include <string>
#include <thread>
#include <vector>

class DirectoryMonitor {
public:
  DirectoryMonitor(const std::vector<std::filesystem::path> &paths);
  ~DirectoryMonitor();
  void start_monitoring();
  void stop_monitoring();
  void add_directory(const std::filesystem::path &path);
  void remove_directory(const std::filesystem::path &path);

private:
  std::vector<std::filesystem::path> directory_paths;
  std::map<std::string, std::set<std::filesystem::path>> previous_files;
  std::thread monitor_thread;
  bool stop_observing = false;
  std::set<std::filesystem::path>
  get_files_in_directory(const std::filesystem::path &path);
  std::condition_variable cv;
  std::mutex cv_m;
  ProcessNewFile process_new_file;
};