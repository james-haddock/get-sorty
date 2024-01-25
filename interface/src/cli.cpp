#include <ftxui/component/captured_mouse.hpp>
#include <ftxui/component/component.hpp>
#include <ftxui/component/component_options.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <boost/interprocess/shared_memory_object.hpp>
#include <boost/interprocess/mapped_region.hpp>
#include <functional>
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <csignal> 

extern char **environ;

using namespace ftxui;

int main() {
    pid_t pid;
    const char* argv[] = {"../service/service", NULL};


    posix_spawnattr_t attr;
    posix_spawnattr_init(&attr);
    posix_spawnattr_setflags(&attr, POSIX_SPAWN_START_SUSPENDED);


    boost::interprocess::shared_memory_object shm;
    try {
        shm = boost::interprocess::shared_memory_object(
            boost::interprocess::create_only,
            "GetShortySharedMemory",
            boost::interprocess::read_write
        );

        shm.truncate(sizeof(int));

        if (posix_spawn(&pid, argv[0], NULL, &attr, const_cast<char* const*>(argv), environ) != 0) {
            perror("posix_spawn");
            exit(EXIT_FAILURE);
        }
    } catch (boost::interprocess::interprocess_exception& e) {

        shm = boost::interprocess::shared_memory_object(
            boost::interprocess::open_only,
            "GetShortySharedMemory",
            boost::interprocess::read_write
        );
    }

    kill(pid, SIGCONT);

    boost::interprocess::mapped_region region(shm, boost::interprocess::read_write);

    void * addr = region.get_address();

    int * command = new (addr) int;

    auto screen = ScreenInteractive::Fullscreen();

    std::vector<std::string> entries = {
        "Start Service",
        "Stop Service",
    };
    int selected = 0;

    MenuOption option;
    option.on_enter = [&] {
        if (selected == 0) {
            *command = 0;
        } else if (selected == 1) {
            *command = 1;
        }
        screen.ExitLoopClosure();
    };
    auto menu = Menu(&entries, &selected, option);

    screen.Loop(menu);

    std::cout << "Selected element = " << selected << std::endl;
}