#include "lox/Parser.hpp"

#include <memory>

#include "lox/Expr.hpp"
#include "lox/Token.hpp"

namespace lox {

    Parser::Parser(std::vector<Token> tokens) : tokens_(tokens){};

    std::shared_ptr<Expr> Parser::expression() {
        { return equality(); }
    }

    std::shared_ptr<Expr> Parser::equality() {
        std::shared_ptr<Expr> expr = comparison();

        auto types = std::vector<TokenType>(
            {TokenType::BANG_EQUAL, TokenType::EQUAL_EQUAL});

        while (match(types)) {
            Token operator_name = previous();
            std::shared_ptr<Expr> right = comparison();

            *expr = Binary(expr, operator_name, right);
        }

        return expr;
    }

    std::shared_ptr<Expr> Parser::term() {
        std::shared_ptr<Expr> expr = factor();

        auto types =
            std::vector<TokenType>({TokenType::MINUS, TokenType::PLUS});

        while (match(types)) {
            Token operator_name = previous();
            std::shared_ptr<Expr> right = factor();

            *expr = Binary(expr, operator_name, right);
        }

        return expr;
    }

    bool Parser::match(std::vector<TokenType> types) {
        for (TokenType type : types) {
            if (check(type)) {
                advance();
                return true;
            }
        }

        return false;
    }

    bool Parser::check(TokenType type) {
        if (isAtEnd()) return false;
        return peek().getTokenType() == type;
    }

    Token Parser::advance() {
        if (!isAtEnd()) current_++;
        return previous();
    }

    bool Parser::isAtEnd() {
        return peek().getTokenType() == TokenType::TOKEN_EOF;
    }

    Token Parser::peek() { return *current_; }

    Token Parser::previous() { return *(current_ - 1); }

    std::shared_ptr<Expr> Parser::comparison() {
        std::shared_ptr<Expr> expr = term();

        auto types = std::vector<TokenType>(
            {TokenType::GREATER, TokenType::GREATER_EQUAL, TokenType::LESS,
             TokenType::LESS_EQUAL});

        while (match(types)) {
            Token operator_name = previous();
            std::shared_ptr<Expr> right = term();
            *expr = Binary(expr, operator_name, right);
        }

        return expr;
    }

    std::shared_ptr<Expr> Parser::factor() { return NULL; };  // TODO
}