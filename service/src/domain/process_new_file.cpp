#include "domain/process_new_file.h"
#include "domain/copy_command.h"
#include <iostream>
    
void ProcessNewFile::process_file(const std::filesystem::path& file) {
    std::string file_extension = file.extension();
    auto it = extension_commands.find(file_extension);
    if (it != extension_commands.end()) {
        std::unordered_map<std::unique_ptr<Command>, std::string> commands = it->second;
        for (const auto& command_pair : commands) {
            command_pair.first->execute(file, command_pair.second);
        }
    }
};