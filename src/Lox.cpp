#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include "lox/Lox.hpp"
#include "lox/Scanner.hpp"
#include "lox/Token.hpp"
#include "lox/TokenType.hpp"
#include "lox/Parser.hpp"   

#include "color/colormod.hpp"
#include "color/color.hpp"

namespace lox 
{

bool Lox::hadError_ = false;

void Lox::runFile(std::string path) {
    std::ifstream inputFile(path);
    std::stringstream buffer;
    buffer << inputFile.rdbuf();
    run(buffer.str());
    inputFile.close();

    if (hadError_) {
        exit(1);
    }
}

void Lox::runPrompt() {
    while (true) {
        std::string line;
        std::cout << "> ";
        getline(std::cin, line);
        run(line);
        hadError_ = false;
    }
}

void Lox::run(std::string source) {
    auto scanner = Scanner(source);
    auto tokens = scanner.scanTokens();

    // for now just print out all the tokens
    for (auto it = tokens.begin(); it != tokens.end(); ++it) {
        auto token = *it;
        std::cerr << yellow_f << token.toString() << "\n" << white_f;
    }

    return;
}

void Lox::error(int line, std::string message) {
    report(line, "", message);
}

void Lox::report(int line, std::string where, std::string message) {
    std::cerr << red_f << "[line " << line << "] Error" << where << ": "  << message << white_f;
}

}