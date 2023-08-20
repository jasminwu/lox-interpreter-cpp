#define TEST_INCLUDE 69

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
     * @brief
     * 
     * @param source 
     */
    static void runFile(std::string source);

    /**
     * @brief 
     * 
     */
    static void runPrompt();

    /**
     * @brief 
     * 
     * @param source 
     */
    static void run(std::string source);

private:
    /**
     * @brief 
     * 
     * @param line 
     * @param message 
     */
    static void error(int line, std::string message);

    /**
     * @brief 
     * 
     * @param line 
     * @param where 
     * @param message 
     */
    static void report(int line, std::string where, std::string message);
};

}