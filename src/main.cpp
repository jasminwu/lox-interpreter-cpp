#include <iostream>

#include "lox/Lox.hpp"

// for pretty colors !!
#include "color/color.hpp"
#include "color/colormod.hpp"

void printGreeting();

int main(int argc, char **argv) {
    // SILLY TEXT PRINTING
    printGreeting();

    // RUN THE PROGRAM
    if (argc > 2) {
        std::cerr << red_f << "Usage: app [script]\n" << white_f;
        return 1;
    } else if (argc == 2) {
        lox::Lox::runFile(argv[1]);
    } else {
        lox::Lox::runPrompt();
    }

    return 0;
}

void printGreeting() {
    // PROJECT NAME
    std::cerr << bold << red_f << "L" << yellow_f << "O" << green_f << "X "
              << cyan_f << "I" << blue_f << "N" << mag_f << "T" << red_f << "E"
              << yellow_f << "R" << green_f << "P" << cyan_f << "R" << blue_f
              << "E" << mag_f << "T" << red_f << "E" << yellow_f << "R" << reset
              << white_f << " - iteration 1\n";

    // CONTRIBUTORS
    std::cerr << blue_f << "by " << green_f << bold << "Jasmin" << reset
              << blue_f << " and " << green_f << bold << "Jeff\n"
              << reset << white_f;
}