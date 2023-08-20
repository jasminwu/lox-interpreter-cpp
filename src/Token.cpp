#include "../include/lox/Token.hpp"

#include "../include/lox/TokenType.hpp"

namespace lox {
    Token::Token(lox::TokenType type, std::string lexeme, std::any literal,
                 int line)
        : type_(type), lexeme_(lexeme), literal_(literal), line_(line){};

    std::string Token::toString() { return ""; }

}