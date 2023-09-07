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

            *expr = Expr.Binary(expr, operator_name, right);
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
        return peek().type_ == type;
    }

    Token Parser::advance() {
        if (!isAtEnd()) current_++;
        return previous();
    }

    bool Parser::isAtEnd() { return peek().type_ == TokenType::TOKEN_EOF; }

    Token Parser::peek() { return tokens_.get(current_); }

    Token Parser::previous() { return tokens.get(current_ - 1); }

    std::shared_ptr<Expr> Parser::comparison() {
        std::shared_ptr<Expr> expr = term();

        auto types = std::vector<TokenType>(
            {TokenType::GREATER, TokenType::GREATER_EQUAL, TokenType::LESS,
             TokenType::LESS_EQUAL});

        while (match(types)) {
            Token operator_name = previous();
            std::shared_ptr<Expr> right = term();
            *expr = Expr.Binary(expr, operator_name, right);
        }

        return expr;
    }

    std::shared_ptr<Expr> Parser::factor() {
        Expr expr = unary();

        auto types =
            std::vector<TokenType>({TokenType::SLASH, TokenType::STAR});

        while (match(types)) {
            Token operator_name = previous();
            Expr right = unary();
            expr = Expr.Binary(expr, operator_name, right);
        }

        return expr;
    }

    std::shared_ptr<Expr> Parser::unary() {
        auto types =
            std::vector<TokenType>({TokenType::BANG, TokenType::MINUS});

        if (match(types)) {
            Token operator_name = previous();
            Expr right = unary();
            return Expr.Unary(operator_name, right);
        }

        return primary();
    }

    std::shared_ptr<Expr> Parser::primary() {
        if (match(std::vector<TokenType>({TokenType::TOKEN_FALSE})))
            return Expr.Literal(false);
        if (match(std::vector<TokenType>({TokenType::TOKEN_TRUE})))
            return Expr.Literal(true);
        if (match(std::vector<TokenType>({TokenType::NIL})))
            return Expr.Literal(null);

        if (match(std::vector<TokenType>(
                {TokenType::NUMBER, TokenType::STRING}))) {
            return Expr.Literal(previous().literal);
        }

        if (match((std::vector<TokenType>({TokenType::LEFT_PAREN}))) {
            Expr expr = expression();
            consume(RIGHT_PAREN, "Expect ')' after expression.");
            return Expr.Grouping(expr);
        }
    }
}