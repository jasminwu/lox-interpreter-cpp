#pragma once

#include <any>
#include <string>

#include "TokenType.hpp"

namespace lox {
    class Token {
    public:
        lox::TokenType type_;
        std::string lexeme_;
        std::any literal_;
        int line_;

        /**
         * @brief Construct a new Token object
         *
         * @param type
         * @param lexeme
         * @param literal
         * @param line
         */
        Token(lox::TokenType type, std::string lexeme, std::any literal,
              int line);

        /**
         * @brief Given a token type, lexeme, literal and a line, it returns a
         * string with all of this information concatenated together
         *
         * @return std::string
         */
        std::string toString();
    };
}