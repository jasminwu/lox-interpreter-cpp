#include "lox/Scanner.hpp"

#include <string>

#include "lox/Lox.hpp"

namespace lox {

    Scanner::Scanner(std::string source) : source_(source){};

    std::vector<Token> Scanner::scanTokens() {
        while (!isAtEnd()) {
            // At beginning of next lexeme
            start_ = current_;
            scanToken();
        }

        std::string empty = "";

        lox::Token current_token(lox::TokenType::TOKEN_EOF, empty,
                                 std::monostate{}, line_);

        tokens.push_back(current_token);

        return tokens;
    }

    // Helper methods

    bool Scanner::isAtEnd() {
        { return current_ >= source_.length(); }
    }

    void Scanner::scanToken() {
        char c = advance();
        switch (c) {
        case '(':
            addToken(lox::TokenType::LEFT_PAREN);
            break;
        case ')':
            addToken(lox::TokenType::RIGHT_PAREN);
            break;
        case '{':
            addToken(lox::TokenType::LEFT_BRACE);
            break;
        case '}':
            addToken(lox::TokenType::RIGHT_BRACE);
            break;
        case ',':
            addToken(lox::TokenType::COMMA);
            break;
        case '.':
            addToken(lox::TokenType::DOT);
            break;
        case '-':
            addToken(lox::TokenType::MINUS);
            break;
        case '+':
            addToken(lox::TokenType::PLUS);
            break;
        case ';':
            addToken(lox::TokenType::SEMICOLON);
            break;
        case '*':
            addToken(lox::TokenType::STAR);
            break;
        case '!':
            addToken(match('=') ? lox::TokenType::BANG_EQUAL
                                : lox::TokenType::BANG);
            break;
        case '=':
            addToken(match('=') ? lox::TokenType::EQUAL_EQUAL
                                : lox::TokenType::EQUAL);
            break;
        case '<':
            addToken(match('=') ? lox::TokenType::LESS_EQUAL
                                : lox::TokenType::LESS);
            break;
        case '>':
            addToken(match('=') ? lox::TokenType::GREATER_EQUAL
                                : lox::TokenType::GREATER);
            break;
        case '/':
            if (match('/')) {
                // A comment goes until the end of the line.
                while (peek() != '\n' && !isAtEnd()) advance();
            } else {
                addToken(lox::TokenType::SLASH);
            }
            break;
        case ' ':
        case '\r':
        case '\t':
            // Ignore whitespace.
            break;
        case '\n':
            line_++;
            break;
        default:
            lox::Lox::error(line_, "Unexpected character.");
            break;
        }
    }

    char Scanner::advance() { return source_[current_++]; }

    void Scanner::addToken(lox::TokenType type) {
        addToken(type, std::monostate{});
    }

    void Scanner::addToken(lox::TokenType type, lox::Literal literal) {
        std::string text = source_.substr(start_, current_ - start_ + 1);

        lox::Token current_token(type, text, literal, line_);
        tokens.push_back(current_token);
    }

    bool Scanner::match(char expected) {
        if (isAtEnd()) return false;
        if (source_[current_] != expected) return false;
        current_++;
        return true;
    }

    char Scanner::peek() {
        if (isAtEnd()) return '\0';
        return source_[current_];
    }

}