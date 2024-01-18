# Get Sorty

#### File Flow Facilitator

This application is a directory observer that watches for changes in specified directories. When a new file or folder is added to a directory, it performs a series of tasks based on the item's attributes. The tasks for each file are configurable by the user.

## Core Features

- Monitor multiple directories for changes
- Perform tasks on new files and directories based on specified attributes
- User-configurable tasks for each file
- Multi-platform functionality (MacOS, Linux, Windows)
- Discreet and efficient background service
- Separate CLI for configuration (connects to the service via API)

## How to Use

1. Configure the tasks for each file extension using the get_sorty_config executable.
2. Run the application.
3. The application will start monitoring the specified directories for changes.
4. When a new file is added to a directory, the application will perform the tasks configured for that file's extension.
