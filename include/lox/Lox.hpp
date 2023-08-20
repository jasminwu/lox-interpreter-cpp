#pragma once

#include <string>

#include "lox/Scanner.hpp"
#include "lox/Token.hpp"
#include "lox/TokenType.hpp"
#include "lox/Parser.hpp"

namespace lox 
{

class Lox {
public:
    static bool hadError_;

    /**
     * @brief runs a lox source file
     * 
     * @param path path to the source file
     */
    static void runFile(std::string path);

    /**
     * @brief begins a command prompt loop
     * 
     */
    static void runPrompt();

    /**
     * @brief runs source code
     * 
     * @param source source code
     */
    static void run(std::string source);

private:
    /**
     * @brief reports an error by given a line number, and an error message
     * 
     * @param line line number
     * @param message error message
     */
    static void error(int line, std::string message);

    /**
     * @brief reports an error given a line number, idk yet, and a message
     * 
     * @param line line number
     * @param where idk yet
     * @param message error message
     */
    static void report(int line, std::string where, std::string message);
};

}