#include "domain/file_lock.h"
#include <unistd.h>

// FOR UNIX SYSTEMS ONLY - MACOS AND LINUX

bool FileLock::is_file_done_copying(const std::filesystem::path& path) {
    int fd = open(path.c_str(), O_RDONLY);
    if (fd == -1) {
        // handle error
        return false;
    }

    struct flock lock;
    lock.l_type = F_RDLCK;

    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;

    if (fcntl(fd, F_SETLK, &lock) == -1) {
        if (errno == EACCES || errno == EAGAIN) {
            // Another process holds the lock
            close(fd);
            return false;
        }
        // handle other errors
    }

    close(fd);
    return true;
}