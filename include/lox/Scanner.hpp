#pragma once

#include <string>
#include <unordered_map>
#include <vector>

#include "Literal.hpp"
#include "Token.hpp"
#include "TokenType.hpp"

namespace lox {

    class Scanner {
    private:
        std::string source_;
        std::vector<Token> tokens;

        const std::unordered_map<std::string, lox::TokenType> keywords = {
            {"and", TokenType::AND},       {"class", TokenType::CLASS},
            {"else", TokenType::ELSE},     {"false", TokenType::TOKEN_FALSE},
            {"for", TokenType::FOR},       {"fun", TokenType::FUN},
            {"if", TokenType::IF},         {"nil", TokenType::NIL},
            {"or", TokenType::OR},         {"print", TokenType::PRINT},
            {"return", TokenType::RETURN}, {"super", TokenType::SUPER},
            {"this", TokenType::THIS},     {"true", TokenType::TOKEN_TRUE},
            {"var", TokenType::VAR},       {"while", TokenType::WHILE}};

        int start_ = 0;
        int current_ = 0;
        int line_ = 1;

        /**
         * @brief Checks whether we have used up all the characters
         *
         * @return true
         * @return false
         */
        bool isAtEnd();

        /**
         * @brief In each turn of the loop, we scan a single token
         *
         */
        void scanToken();

        /**
         * @brief Consumes the next character in the source file and returns it
         *
         * @return char
         */
        char advance();

        /**
         * @brief addToken grabs the text of the current lexeme and creates a
         * new token for it. Supports literal type also.
         *
         * @param type
         */
        void addToken(lox::TokenType type);
        void addToken(lox::TokenType type, lox::LiteralType literal);

        /**
         * @brief This method resembles conditional advance(). We only consume
         * the current character if it's what we're looking for.
         *
         * @param expected
         * @return true
         * @return false
         */
        bool match(char expected);

        /**
         * @brief Similar to advance(), but does not consume the
         * character. This is called lookahead. Since it only looks at the
         * current unconsumed character, we have one character of lookahead.
         *
         * @return char
         */
        char peek();

        /**
         * @brief We consume characters until we hit the " that ends the string.
         * We also gracefully handle running out of input before the string is
         * closed and report an error for that.
         *
         */
        void string();

        /**
         * @brief Checks whether a char c is a digit
         *
         * @param c
         * @return true
         * @return false
         */
        bool isDigit(char c);

        /**
         * @brief Consumes the rest of the number literal in a similar way to
         * how we handle strings
         *
         */
        void number();

        /**
         * @brief Look ahead if current character is not the last one
         *
         * @return char
         */
        char peekNext();

        /**
         * @brief We advance to the end of the identifier and then add it as a
         * token
         *
         */
        void identifier();

        /**
         * @brief Determines whether a char is alphanumeric (is a letter or
         * number)
         *
         * @param c
         * @return true
         * @return false
         */
        bool isAlphaNumeric(char c);

        /**
         * @brief
         *
         * @param c
         * @return true
         * @return false
         */
        bool isAlpha(char c);

    public:
        /**
         * @brief Construct a new Scanner object
         *
         * @param source - Contents of the source file in string form
         */
        Scanner(std::string source);

        /**
         * @brief Turns source code into a list of tokens
         *
         * @return std::vector<Token>
         */
        std::vector<Token> scanTokens();
    };

}