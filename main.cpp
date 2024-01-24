#include <cstdlib>
#include <iostream>
#include <unistd.h>

int main() {
    pid_t pid1, pid2;

    // Launch the first executable in a new terminal window
    if ((pid1 = fork()) == 0) {
        std::cout << "initialising service\n";
        execlp("gnome-terminal", "gnome-terminal", "--", "./service/service", nullptr);
        exit(EXIT_FAILURE);
    } else if (pid1 < 0) {
        std::cerr << "Error forking process 1." << std::endl;
        exit(EXIT_FAILURE);
    }

    // Launch the second executable in a new terminal window
    if ((pid2 = fork()) == 0) {
        std::cout << "initialising interface\n";
        execlp("gnome-terminal", "gnome-terminal", "--", "./interface/interface", nullptr);
        exit(EXIT_FAILURE);
    } else if (pid2 < 0) {
        std::cerr << "Error forking process 2." << std::endl;
        exit(EXIT_FAILURE);
    }

    return 0;
}
