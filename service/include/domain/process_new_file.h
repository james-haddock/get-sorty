#ifndef PROCESS_NEW_FILE_H
#define PROCESS_NEW_FILE_H
#include "domain/command.h"
#include "domain/copy_command.h"
#include "domain/file_lock.h"

#include <filesystem>
#include <iostream>

class ProcessNewFile {
public:
	ProcessNewFile(){};
	void process_file(const std::filesystem::path &file);
	std::shared_ptr<Command> copyCommand = std::make_shared<CopyCommand>();
	
	std::unordered_map<std::string,
										 std::unordered_map<std::shared_ptr<Command>, std::string>>		 
			extension_commands = {
					{".epub",
					{{copyCommand,
						"/Users/jameshaddock/Desktop/Coding/Projects/get_sorty/service/"
						"test/testdir1/copyto"}}}};
	FileLock file_lock;
};

#endif