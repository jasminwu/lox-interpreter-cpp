#include <iostream>

#include "lox/Lox.hpp"

int main(int argc, char **argv) {
    std::cout << "Lox Interpreter - Iteration 1 \n";
    std::cout << "by Jasmin and Jeff \n";

    if (argc > 2) {
        std::cout << "Usage: app [script]\n";
        return 1;
    } else if (argc == 2) {
        std::cout << "Preparing to run file...\n";
        lox::Lox::runFile(argv[1]);
    } else {
        std::cout << "Initialising command prompt...\n";
        lox::Lox::runPrompt();
    }

    return 0;
}