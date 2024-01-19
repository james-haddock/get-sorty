#ifndef PROCESS_NEW_FILE_H
#define PROCESS_NEW_FILE_H
#include "domain/command.h"

#include <filesystem>
#include <iostream>

class ProcessNewFile {
    public:
    ProcessNewFile();
    void process_file(const std::filesystem::path& file);
    std::unordered_map<std::string, std::unordered_map<std::unique_ptr<Command>, std::string>> extension_commands;
};

#endif