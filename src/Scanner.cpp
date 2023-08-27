#include <string>

#include "lox/Scanner.hpp"

namespace lox
{

Scanner::Scanner(std::string source) : source_(source){};

std::vector<Token> Scanner::scanTokens() {
    // FOR TESTING
    tokens.push_back({
        lox::TokenType::STRING,  
        "\"Hello, world!\"",
        "Hello, world!",
        1
    });

    // TODO: REMOVE THIS AND ACTUALLY SCAN THE TOKENS

    return tokens;
}

}