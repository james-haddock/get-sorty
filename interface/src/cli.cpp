#include <boost/asio.hpp>
#include <ftxui/component/captured_mouse.hpp>
#include <ftxui/component/component.hpp>
#include <ftxui/component/component_options.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

using namespace ftxui;
using boost::asio::local::stream_protocol;

int main() {
    auto screen = ScreenInteractive::TerminalOutput();

    std::vector<std::string> entries = {
            "entry 1",
            "entry 2",
            "entry 3",
    };
    int selected = 0;

    MenuOption option;
    option.on_enter = screen.ExitLoopClosure();
    auto menu = Menu(&entries, &selected, option);

    boost::asio::io_service io_service;
    stream_protocol::acceptor acceptor(io_service, stream_protocol::endpoint("/tmp/get_sorty_socket"));
    stream_protocol::socket socket(io_service);
    acceptor.accept(socket);

    screen.Loop(std::make_shared<ComponentBase>([&] {
        menu->Render();
        boost::asio::read(socket, boost::asio::buffer(&selected, sizeof(selected)));
    }));

    std::cout << "Selected element = " << selected << std::endl;
}