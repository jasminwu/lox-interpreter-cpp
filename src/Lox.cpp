#include "lox/Lox.hpp"

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include "color/color.hpp"
#include "color/colormod.hpp"
#include "lox/Parser.hpp"
#include "lox/Scanner.hpp"
#include "lox/Token.hpp"
#include "lox/TokenType.hpp"

namespace lox {

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
        std::string line;

        while (true) {
            std::cout << "> ";

            try {
                if (!std::getline(std::cin, line)) {
                    if (std::cin.eof()) {
                        break;
                    } else {
                        throw std::runtime_error("Error reading input");
                    }
                }

                run(line);
                hadError_ = false;
            } catch (const std::exception& e) {
                std::cerr << "Error: " << e.what() << std::endl;
            }
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
        std::cerr << red_f << "[line " << line << "] Error" << where << ": "
                  << message << white_f;

        hadError_ = true;
    }

}