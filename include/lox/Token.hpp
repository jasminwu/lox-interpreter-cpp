#pragma once

#include <string>
#include <variant>

#include "lox/TokenType.hpp"
#include "lox/Literal.hpp"

namespace lox 
{

class Token {
public:
    lox::TokenType type_;
    std::string lexeme_;
    lox::Literal literal_;
    int line_;

    /**
     * @brief Construct a new Token object
     *
     * @param type
     * @param lexeme
     * @param literal
     * @param line
     */
    Token(lox::TokenType type, std::string lexeme, lox::Literal literal,
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