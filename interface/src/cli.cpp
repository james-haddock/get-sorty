#include <boost/asio.hpp>
#include <ftxui/component/captured_mouse.hpp>
#include <ftxui/component/component.hpp>
#include <ftxui/component/component_options.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <functional>
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace ftxui;
using boost::asio::local::stream_protocol;

int main() {
    const char* executablePath = "../service/service";
            std::system((std::string(executablePath) + " &").c_str());
    auto screen = ScreenInteractive::TerminalOutput();

    std::vector<std::string> entries = {
            "Start service",
            "Stop service",
    };
    int selected = 0;

    MenuOption option;
    option.on_enter = [&] {
        boost::asio::io_service io_service;
        stream_protocol::socket socket(io_service);
        socket.connect(stream_protocol::endpoint("/tmp/get_sorty_socket"));
        boost::asio::write(socket, boost::asio::buffer(std::to_string(selected)));
        char response[128];
        boost::asio::read(socket, boost::asio::buffer(response, sizeof(response)));
        std::cout << "Service response: " << response << std::endl;
    };
    auto menu = Menu(&entries, &selected, option);

    screen.Loop(menu);
}