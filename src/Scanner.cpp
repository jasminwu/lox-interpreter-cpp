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

        std::string empty = std::string("");

        lox::Token current_token(lox::TokenType::TOKEN_EOF, empty,
                                 std::monostate(), line_);

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
        case '"':
            string();
            break;
        default:
            if (isDigit(c)) {
                number();
            } else if (isAlpha(c)) {
                identifier();
            } else {
                Lox::error(line_, "Unexpected character.");
            }
            break;
        }
    }

    char Scanner::advance() { return source_[current_++]; }

    void Scanner::addToken(lox::TokenType type) {
        addToken(type, std::monostate());
    }

    void Scanner::addToken(lox::TokenType type, lox::Literal literal) {
        std::string text = source_.substr(start_, current_ - start_);

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

    void Scanner::string() {
        while (peek() != '"' && !isAtEnd()) {
            if (peek() == '\n') line_++;
            advance();
        }

        if (isAtEnd()) {
            Lox::error(line_, std::string("Unterminated string."));
            return;
        }

        // The closing ".
        advance();

        // Trim the surrounding quotes.
        int first_char = start_ + 1;
        int last_char = current_ - 1;

        std::string value = source_.substr(first_char, last_char - first_char);
        addToken(lox::TokenType::STRING, value);
    }

    bool Scanner::isDigit(char c) { return c >= '0' && c <= '9'; }

    void Scanner::number() {
        while (isDigit(peek())) advance();

        // Look for a fractional part.
        if (peek() == '.' && isDigit(peekNext())) {
            // Consume the "."
            advance();

            while (isDigit(peek())) advance();
        }

        addToken(TokenType::NUMBER,
                 std::stod(source_.substr(start_, current_ - start_)));
    }

    char Scanner::peekNext() {
        if (current_ + 1 >= source_.length()) return '\0';
        return source_[current_ + 1];
    }

    void Scanner::identifier() {
        while (isAlphaNumeric(peek())) advance();

        std::string text = source_.substr(start_, current_ - start_);
        if (keywords.find(text) == keywords.end()) {
            addToken(TokenType::IDENTIFIER);
        } else {
            addToken(keywords.at(text));
        }
    }

    bool Scanner::isAlpha(char c) {
        return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_';
    }

    bool Scanner::isAlphaNumeric(char c) { return isAlpha(c) || isDigit(c); }
}