# Get Sorty
<p align="center">
  <img src="https://github.com/james-haddock/get_sorty/assets/123553781/37dd4f76-2466-443c-b761-2b8af27a677e" width="500px" alt="vecteezy_computer-character-retro-mascot-character_24659690">
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

## Software Design
- **Layered Architecture**: Get Sorty follows a layered architecture design, which helps in separating concerns and making the codebase easier to maintain and extend. The architecture is divided into the following layers:
    - **Domain Layer**: This layer contains the core business logic of the application. It includes classes and functions for processing new files, moving files, and locking files.
    - **Infrastructure Layer**: This layer provides concrete implementations of the interfaces defined in the domain layer. It includes classes for monitoring directories.
    - **Application Layer**: This layer orchestrates the use cases of the system. It includes the main service that ties everything together.
    - **Interface Layer**: This layer defines how external systems or users interact with the application. It includes the Command Line Interface (CLI) for configuring the application.
    - **Configuration Layer**: This layer handles the user configuration settings. It includes classes for parsing and managing user configuration.
 
Each layer has a specific role and interacts with the other layers in a controlled manner. This separation of concerns makes the code easier to understand, test, and maintain.

- **Concurrency Model**: The application makes use of multithreading to enhance performance and maintain the responsiveness of the core application functionality. Each command execution, such as the `CopyCommand`, is handled in a separate thread. This means that the process of copying files, which could be time-consuming if there are large files or a large number of files, does not block the main thread that the application uses to monitor directories and respond to user input.

    By offloading these potentially long-running tasks to auxiliary threads, the application ensures that the core functionality remains responsive. This means that even if a large copy operation is in progress, the application can continue to monitor directories and process new files.

    This use of multithreading is a key aspect of the application's concurrency model. It allows the application to efficiently handle multiple tasks simultaneously, improving the overall performance and user experience.
  
- **Scalability and Maintainability with Design Patterns**: The application is designed with scalability and maintainability in mind. One of the key design patterns used in the application is the Command pattern. This pattern is used to encapsulate each request as an object, thereby letting you parameterize clients with different requests, queue or log requests, and support undoable operations.

    The `Command` class in the domain layer is an abstract base class that declares an interface for executing operations. Classes like `CopyCommand` extend this base class and implement the `execute` method. This design makes it easy to add new commands in the future. To add a new command, we simply need to create a new class that extends the `Command` class and implement the `execute` method.

    This use of the Command pattern allows the application to scale in terms of functionality. As the requirements of the application grow, new commands can be added as separate classes without modifying the existing code. This contributes to the maintainability of the codebase, as existing code does not need to be changed each time a new feature is added.

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

<a href="https://www.vecteezy.com/free-vector/cartoon">Cartoon Vectors by Vecteezy</a>
