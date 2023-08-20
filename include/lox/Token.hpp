#pragma once

#include <any>
#include <string>

#include "TokenType.hpp"

namespace lox {
    class Token {
        public:
        // Member variables
        lox::TokenType type_;
        std::string lexeme_;
        std::any literal_;
        int line_;

        // Constructor
        Token(lox::TokenType type, std::string lexeme, std::any literal,
              int line);

        // Converts to string
        std::string toString();
    };
}