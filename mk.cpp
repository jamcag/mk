#include <cstdlib>
#include <iostream>
#include <string>

int main(int argc, char** argv) {
    if (argc == 1 || argc > 2) {
        std::cerr << "error: Needs one argument.";
        return EXIT_FAILURE;
    }
    const char* name = argv[1];

    std::string command = "g++ -Wall -fsanitize=address -std=c++20 ";
    command += name;
    command += ".cpp ";
    command += "-o ";
    command += name;
    int ret = std::system(command.c_str());
    if (ret) {
        std::cerr << "error: Compilation failed";
        return EXIT_FAILURE;
    }
}
