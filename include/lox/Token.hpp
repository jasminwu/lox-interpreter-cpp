#pragma once

#include <string>
#include <unordered_map>
#include <variant>

#include "lox/LiteralType.hpp"
#include "lox/TokenType.hpp"

namespace lox {
    class Token {
    private:
        lox::TokenType type_;
        std::string lexeme_;
        lox::LiteralType literal_;
        int line_;

        std::unordered_map<lox::TokenType, std::string> tokenTypes_ = {
            {lox::TokenType::LEFT_PAREN, "LEFT_PAREN"},
            {lox::TokenType::RIGHT_PAREN, "RIGHT_PAREN"},
            {lox::TokenType::LEFT_BRACE, "LEFT_BRACE"},
            {lox::TokenType::RIGHT_BRACE, "RIGHT_BRACE"},
            {lox::TokenType::COMMA, "COMMA"},
            {lox::TokenType::DOT, "DOT"},
            {lox::TokenType::MINUS, "MINUS"},
            {lox::TokenType::PLUS, "PLUS"},
            {lox::TokenType::SEMICOLON, "SEMICOLON"},
            {lox::TokenType::SLASH, "SLASH"},
            {lox::TokenType::STAR, "STAR"},
            {lox::TokenType::BANG, "BANG"},
            {lox::TokenType::BANG_EQUAL, "BANG_EQUAL"},
            {lox::TokenType::EQUAL, "EQUAL"},
            {lox::TokenType::EQUAL_EQUAL, "EQUAL_EQUAL"},
            {lox::TokenType::GREATER, "GREATER"},
            {lox::TokenType::GREATER_EQUAL, "GREATER_EQUAL"},
            {lox::TokenType::LESS, "LESS"},
            {lox::TokenType::LESS_EQUAL, "LESS_EQUAL"},
            {lox::TokenType::IDENTIFIER, "IDENTIFIER"},
            {lox::TokenType::STRING, "STRING"},
            {lox::TokenType::NUMBER, "NUMBER"},
            {lox::TokenType::AND, "AND"},
            {lox::TokenType::CLASS, "CLASS"},
            {lox::TokenType::ELSE, "ELSE"},
            {lox::TokenType::TOKEN_FALSE, "TOKEN_FALSE"},
            {lox::TokenType::FUN, "FUN"},
            {lox::TokenType::FOR, "FOR"},
            {lox::TokenType::IF, "IF"},
            {lox::TokenType::NIL, "NIL"},
            {lox::TokenType::OR, "OR"},
            {lox::TokenType::PRINT, "PRINT"},
            {lox::TokenType::RETURN, "RETURN"},
            {lox::TokenType::SUPER, "SUPER"},
            {lox::TokenType::THIS, "THIS"},
            {lox::TokenType::TOKEN_TRUE, "TOKEN_TRUE"},
            {lox::TokenType::VAR, "VAR"},
            {lox::TokenType::WHILE, "WHILE"},
            {lox::TokenType::TOKEN_EOF, "TOKEN_EOF"}};

        /**
         * @brief Converts a Literal type to a string. Only to be used in the
         * toString method.
         *
         * @param literal
         * @return std::string
         */
        std::string literalToString(const lox::LiteralType& literal);
        friend bool operator==(Token const a, Token const b);
        friend bool operator!=(Token const a, Token const b);

    public:
        // makes a dummy token
        Token();

        /**
         * @brief Construct a new Token object
         *
         * @param type
         * @param lexeme
         * @param literal
         * @param line
         */
        Token(lox::TokenType type, std::string lexeme, lox::LiteralType literal,
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