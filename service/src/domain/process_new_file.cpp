#include "domain/process_new_file.h"
#include <iostream>

ProcessNewFile::ProcessNewFile() {};
    
void ProcessNewFile::process_file(std::filesystem::path file) {
    std::string file_extension = file.extension();
    auto it = extension_commands.find(file_extension);
    if (it != extension_commands.end()) {
        std::vector<std::string> commands = it->second;
        for (const auto& command : commands) {
        }
    }
};

