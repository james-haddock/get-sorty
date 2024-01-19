#ifndef COPY_COMMAND_H
#define COPY_COMMAND_H

#include "domain/command.h"
#include <iostream>
#include <filesystem>

class CopyCommand : public Command {
public:
void execute(const std::filesystem::path &item_to_move,
             const std::string &destination_directory) override {
    std::filesystem::path destination_path(destination_directory);
    destination_path /= item_to_move.filename(); 
    std::filesystem::rename(item_to_move, destination_path);
    std::cout << item_to_move << " moved to directory " << destination_path << "\n";
}
};

#endif