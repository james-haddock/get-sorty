#include "infrastructure/directory_monitor.h"
#include <ftxui/component/component.hpp> 
#include <ftxui/component/screen_interactive.hpp>
#include <boost/asio.hpp>
#include <chrono>
#include <filesystem>
#include <iostream>
#include <set>
#include <thread>
#include <vector>

using namespace ftxui;
using boost::asio::local::stream_protocol;

int main() {
  std::cout << "Get Sorty!\n";
  std::vector<std::filesystem::path> directory_paths_to_monitor;
  // retrieve directories to monitor from get_sorty_config.TOML
  directory_paths_to_monitor = {"/Users/jameshaddock/Desktop/Coding/Projects/get_sorty/service/test/testdir1"};
  // check integrity of the file paths that have been stored
  DirectoryMonitor directoryMonitor(directory_paths_to_monitor);

  std::vector<std::string> entries = {
      "Start monitoring",
      "Stop monitoring",
  };
  int selected = 0;

  MenuOption option;
  option.on_enter = [&] {
    if (selected == 0) {
      directoryMonitor.start_monitoring();
    } else if (selected == 1) {
      directoryMonitor.stop_monitoring();
    }
  };

  auto screen = ScreenInteractive::TerminalOutput();
  auto menu = Menu(&entries, &selected, option);

  boost::asio::io_service io_service;
  stream_protocol::socket socket(io_service);
  socket.connect(stream_protocol::endpoint("/tmp/get_sorty_socket"));

  screen.Loop(std::make_shared<ComponentBase>([&] {
    menu->Render();
    boost::asio::write(socket, boost::asio::buffer(std::to_string(selected)));
  }));

  return 0;
}