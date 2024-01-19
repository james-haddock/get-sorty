#include <filesystem>
#include <fcntl.h>

// FOR UNIX SYSTEMS ONLY - MACOS AND LINUX

class FileLock {
public:
    bool is_file_done_copying(const std::filesystem::path& path);
};