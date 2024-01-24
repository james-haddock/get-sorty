#ifdef __unix__
#include <cstdlib>
#endif
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
  #ifdef __unix__
    system("./service > /dev/null 2>&1 &");
#endif
  std::cout << "Get Sorty!\n";
  std::vector<std::filesystem::path> directory_paths_to_monitor;
  // retrieve directories to monitor from get_sorty_config.TOML
  directory_paths_to_monitor = {"/Users/jameshaddock/Desktop/Coding/Projects/get_sorty/service/test/testdir1"};
  // check integrity of the file paths that have been stored
  DirectoryMonitor directoryMonitor(directory_paths_to_monitor);

  boost::asio::io_service io_service;
  stream_protocol::acceptor acceptor(io_service, stream_protocol::endpoint("/tmp/get_sorty_socket"));
  stream_protocol::socket socket(io_service);
  acceptor.accept(socket);

  for (;;) {
    int command;
    boost::asio::read(socket, boost::asio::buffer(&command, sizeof(command)));
    if (command == 0) {
      directoryMonitor.start_monitoring();
      std::string response = "Service started\n";
      boost::asio::write(socket, boost::asio::buffer(response));
    } else if (command == 1) {
      directoryMonitor.stop_monitoring();
      std::string response = "Service stopped\n";
      boost::asio::write(socket, boost::asio::buffer(response));
    }
  }

  return 0;
}