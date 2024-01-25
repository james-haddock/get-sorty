#include <cstdlib>
#include <iostream>
#include <unistd.h>

int main() {
    const char* firstExecutable = "./service/service";
    const char* secondExecutable = "./interface/interface";

    // Start the first executable
    if (fork() == 0) {
        close(STDOUT_FILENO);
        close(STDERR_FILENO);
        setsid();
        if (execl(firstExecutable, firstExecutable, nullptr) == -1) {
            perror("Error starting the first executable");
            exit(EXIT_FAILURE);
        }
    }


    // Start the second executable
    if (fork() == 0) {
        if (execl(secondExecutable, secondExecutable, nullptr) == -1) {
            perror("Error starting the second executable");
            exit(EXIT_FAILURE);
        }
    }

    return 0;
}


