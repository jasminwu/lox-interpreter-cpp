#include <string>

#include "lox/Scanner.hpp"

namespace lox
{

Scanner::Scanner(std::string source) : source_(source){};

std::vector<Token> Scanner::scanTokens() {
    return tokens;
}

}