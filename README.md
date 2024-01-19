# Get Sorty
<p align="center">
  <img src="https://github.com/james-haddock/get_sorty/assets/123553781/37dd4f76-2466-443c-b761-2b8af27a677e" width="300px" alt="vecteezy_computer-character-retro-mascot-character_24659690">
</p>

## Overview
Get Sorty is a powerful, user-configurable file flow facilitator. It's designed to monitor multiple directories simultaneously and perform user-defined actions based on the attributes of new files or folders added to these directories. This application is a discreet and efficient background service that works across multiple platforms including MacOS, Linux, and Windows. Built in C++ for speed and efficiency.

## Core Features
- **Directory Monitoring**: Get Sorty can monitor multiple directories at once, watching for any changes such as the addition of new files or folders.
- **Attribute-Based Actions**: The application can perform tasks on new files and folders based on their attributes. This includes actions based on file type, size, creation date, and more.
- **User-Configurable Tasks**: Users can define what actions Get Sorty should take when it detects a new file or folder. This includes moving the file to a new location, renaming the file, opening the file with a specific program, and more.
- **Multi-Platform Functionality**: Get Sorty is designed to work on MacOS, Linux, and Windows. It can handle platform-specific file systems and paths.
- **Multithreading**: Get Sorty implements multithreading to perform multiple actions simultaneously. This allows it to efficiently handle large numbers of files and directories without slowing down your system.
- **Background Service**: Get Sorty runs as a background service, quietly monitoring your directories without interrupting your work. It uses efficient algorithms and system calls to minimize CPU and memory usage.
- **Configuration CLI**: Get Sorty comes with a separate command-line interface for configuration. This CLI connects to the Get Sorty service via an API, allowing you to configure Get Sorty without stopping the service.

## Building from Source (MacOS / Linux)
If you want to build Get Sorty from source, you'll need a C++ compiler and the CMake build system. Here are the steps to build Get Sorty:
1. Clone the Get Sorty repository.
2. Navigate to the repository directory.
3. Create a build folder in the root of the repository.
4. Run cmake .. from within the new build directory to generate the build files.
5. Run make to build the Get Sorty executables.

## How to Use
1. Install Get Sorty: Download the latest release and install it on your system.
2. Configure Tasks: Use the get_sorty_config executable to configure the tasks for each file extension. You can specify what actions Get Sorty should take when it detects a new file with a certain extension.
3. Run Get Sorty: Start the Get Sorty service. It will begin monitoring the directories you specified.
4. Let Get Sorty Handle Your Files: When a new file is added to a monitored directory, Get Sorty will automatically perform the tasks you configured for that file's extension.


## License
Get Sorty is licensed under the MIT License. See the LICENSE file for more details.

[Cartoon Vectors by Vecteezy](https://www.vecteezy.com/free-vector/cartoon)
