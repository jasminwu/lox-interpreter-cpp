#include "lox/Parser.hpp"

#include <memory>
#include <stdexcept>

#include "lox/Expr.hpp"
#include "lox/Token.hpp"

namespace lox {

    Parser::Parser(std::vector<Token> tokens) : tokens_(tokens){};

    std::shared_ptr<Expr> Parser::expression() {
        return equality();
    }

    std::shared_ptr<Expr> Parser::equality() {
        auto expr = comparison();

        auto types = std::vector<TokenType>(
            {TokenType::BANG_EQUAL, TokenType::EQUAL_EQUAL});

        while (match(types)) {
            auto operator_name = previous();
            auto right = comparison();

            expr = std::make_shared<Binary>(expr, operator_name, right);
        }

        return expr;
    }

    std::shared_ptr<Expr> Parser::term() {
        auto expr = factor();

        auto types =
            std::vector<TokenType>({TokenType::MINUS, TokenType::PLUS});

        while (match(types)) {
            auto operator_name = previous();
            auto right = factor();

            expr = std::make_shared<Binary>(expr, operator_name, right);
        }

        return expr;
    }

    bool Parser::match(std::vector<TokenType> types) {
        for (auto type : types) {
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

    Token Parser::peek() {
        return *current_;
    }

    Token Parser::previous() {
        return *(current_ - 1);
    }

    Token Parser::consume(std::vector<TokenType> types, std::string error_msg) {
        if (match(types)) {
            return advance();
        } else {
            throw std::invalid_argument(error_msg);
        }
    }

    std::shared_ptr<Expr> Parser::comparison() {
        auto expr = term();

        auto types = std::vector<TokenType>(
            {TokenType::GREATER, TokenType::GREATER_EQUAL, TokenType::LESS,
             TokenType::LESS_EQUAL});

        while (match(types)) {
            auto operator_name = previous();
            auto right = term();
            expr = std::make_shared<Binary>(expr, operator_name, right);
        }

        return expr;
    }

    std::shared_ptr<Expr> Parser::factor() {
        auto expr = unary();

        while (match({TokenType::SLASH, TokenType::STAR})) {
            auto operator_name = previous();
            auto right = unary();
            expr = make_shared<Binary>(expr, operator_name, right);
        }

        return expr;
    };

    std::shared_ptr<Expr> Parser::unary() {
        if (match({TokenType::BANG, TokenType::MINUS})) {
            auto operator_name = previous();
            auto right = unary();
            
            return std::make_shared<Unary>(operator_name, right);
        }

        return primary();
    }

    std::shared_ptr<Expr> Parser::primary() {
        if (match({
                TokenType::TOKEN_FALSE, TokenType::TOKEN_TRUE, TokenType::NIL, 
                TokenType::NUMBER, TokenType::STRING })) {
            return std::make_shared<Literal>(previous());
        }

        if (match({TokenType::LEFT_PAREN})) {
            auto expr = expression();
            consume({TokenType::RIGHT_PAREN}, "Expect ')' after expression.");
            return std::make_shared<Grouping>(expr);
        }

        return nullptr;
        // to be continued
    }

}