#include <iostream>
#include <memory>
#include <variant>

#include "lox/Lox.hpp"
#include "lox/ASTHeight.hpp"
#include "lox/Expr.hpp"

// for pretty colors !!
#include "color/color.hpp"
#include "color/colormod.hpp"

void printGreeting();

int main(int argc, char **argv) {
    // SILLY TEXT PRINTING
    printGreeting();

    // BEGIN RANDOM TEST ///////////////////////////
    lox::Token hii = {lox::TokenType::STRING, "\"hello\"", "hello", 1};
    lox::Token sex = {lox::TokenType::NUMBER, "69", (double) 69, 1};
    lox::Token opp = {lox::TokenType::PLUS, "+", std::monostate(), 1};

    auto left = std::make_shared<lox::Literal>(hii);
    auto right = std::make_shared<lox::Literal>(sex);
    auto root = std::make_shared<lox::Binary>(left, opp, right);



    // END RANDOM TEST /////////////////////////////
    

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