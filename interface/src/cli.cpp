#include <ftxui/component/captured_mouse.hpp>
#include <ftxui/component/component.hpp>
#include <ftxui/component/component_options.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <boost/interprocess/shared_memory_object.hpp>
#include <boost/interprocess/mapped_region.hpp>
#include <spawn.h>
#include <functional>
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <csignal>

extern char **environ;

using namespace ftxui;

int main() {

    boost::interprocess::shared_memory_object shm;

    shm = boost::interprocess::shared_memory_object(
        boost::interprocess::open_only,
        "GSSharedMemory",
        boost::interprocess::read_write
    );

    boost::interprocess::mapped_region region(shm, boost::interprocess::read_write);

    void * addr = region.get_address();

    int * command = static_cast<int*>(addr);

    auto screen = ScreenInteractive::Fullscreen();

    std::vector<std::string> entries = {
        "Start Service",
        "Stop Service",
        "Exit TUI",
        "Exit TUI and Service",
    };
    int selected = 0;

    MenuOption option;
    option.on_enter = [&] {
        if (selected == 0) {
            *command = 0;
        } else if (selected == 1) {
            *command = 1;
        } else if (selected == 2) {
            // Exit TUI
            *command = 1;
            screen.ExitLoopClosure();
        } else if (selected == 3) {
            *command = 1;
            // Exit TUI and Service
            // kill(pid, SIGTERM);
            screen.ExitLoopClosure();
        }
    };
    auto menu = Menu(&entries, &selected, option);

    std::string banner = R"(
                                                                                       
     _/_/_/              _/            _/_/_/                        _/                
  _/          _/_/    _/_/_/_/      _/          _/_/    _/  _/_/  _/_/_/_/  _/    _/   
 _/  _/_/  _/_/_/_/    _/            _/_/    _/    _/  _/_/        _/      _/    _/    
_/    _/  _/          _/                _/  _/    _/  _/          _/      _/    _/     
 _/_/_/    _/_/_/      _/_/      _/_/_/      _/_/    _/            _/_/    _/_/_/      
                                                                              _/       
                                                                         _/_/          
)";

auto banner_component = Renderer([&] {
    return text(banner);
});

auto container = Container::Vertical({
    banner_component,
    menu,
});

    screen.Loop(container);

    std::cout << "Selected element = " << selected << std::endl;
}