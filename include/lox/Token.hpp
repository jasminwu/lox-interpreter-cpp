#pragma once

#include <string>
#include <variant>

#include "TokenType.hpp"

namespace lox 
{

class Token {
public:
    lox::TokenType type_;
    std::string lexeme_;
    std::variant<std::monostate, double, std::string> literal_;
    int line_;

    /**
     * @brief Construct a new Token object
     *
     * @param type
     * @param lexeme
     * @param literal
     * @param line
     */
    Token(lox::TokenType type, std::string lexeme, std::variant<std::monostate, double, std::string> literal,
            int line);

    /**
     * @brief Given a token type, lexeme, literal and a line, it returns a
     * string with all of this information concatenated together
     *
     * @return std::string
     */
    std::string toString();

    friend bool operator==(Token const a, Token const b);
    friend bool operator!=(Token const a, Token const b);
};

}