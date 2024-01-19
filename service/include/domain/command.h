#ifndef COMMAND_H
#define COMMAND_H

#include <iostream>
#include <filesystem>

class Command {
public:
    virtual ~Command() {}

    virtual void execute(const std::filesystem::path& item, const std::string& argument) = 0;
};

#endif
