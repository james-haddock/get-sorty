#include <filesystem>
# include <iostream>

class ProcessNewFile {
    public:
    ProcessNewFile();
    void process_file(std::filesystem::path file);
    std::unordered_map<std::string, std::vector<std::string>> extension_commands;
};