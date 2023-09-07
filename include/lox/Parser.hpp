#pragma once

#include <vector>

#include "lox/Expr.hpp"

namespace lox {

    class Parser {
    private:
        std::vector<lox::Token> tokens_;             // list of tokens
        std::vector<lox::Token>::iterator current_;  // iterator on list

        /**
         * @brief This method basically expands to the equality rule
         *
         * @return std::shared_ptr<Expr>
         */
        std::shared_ptr<Expr> expression();

        /**
         * @brief Used for any equalities present in the code. Stores an
         * expression that contains LHS, operator, and RHS
         *
         * @return std::shared_ptr<Expr>
         */
        std::shared_ptr<Expr> equality();

        /**
         * @brief For addition and subtraction
         *
         * @return std::shared_ptr<Expr>
         */
        std::shared_ptr<Expr> term();

        /**
         * @brief Checks to see if the current token has any of the given
         * types. If so, it consumes the token and returns true. Otherwise,
         * it returns false and leaves the current token alone.
         *
         * @param types
         * @return true
         * @return false
         */
        bool match(std::vector<TokenType> types);

        /**
         * @brief The check() method returns true if the current token is of the
         * given type. Unlike match(), it never consumes the token, it only
         * looks at it.
         *
         * @param type
         * @return true
         * @return false
         */
        bool check(TokenType type);

        /**
         * @brief The advance() method consumes the current token and returns
         * it, similar to how the scanner's corresponding method went through
         * characters.
         *
         * @return Token
         */
        Token advance();

        /**
         * @brief Checks if we have run out of tokens to parse
         *
         * @return true
         * @return false
         */
        bool isAtEnd();

        /**
         * @brief returns the current token we have yet to consume
         *
         * @return Token
         */
        Token peek();

        /**
         * @brief Returns the most recently consumed token
         *
         * @return Token
         */
        Token previous();

        /**
         * @brief Used for any comparisons present in the code. Stores an
         * expression that contains LHS, operator, and RHS
         *
         * @return std::shared_ptr<Expr>
         */
        std::shared_ptr<Expr> comparison();

        /**
         * @brief Used for multiplication and division operations
         *
         * @return std::shared_ptr<Expr>
         */
        std::shared_ptr<Expr> factor();

        /**
         * @brief Again, we look at the current token to see how to parse. If
         * it is a ! or -, we must have a unary expression. In that case, we
         * grab the token and then recursively call unary() again to parse the
         * operand.
         *
         * @return std::shared_ptr<Expr>
         */
        std::shared_ptr<Expr> unary();

        /**
         * @brief Parsing primary expressions
         *
         * @return std::shared_ptr<Expr>
         */
        std::shared_ptr<Expr> primary();

    public:
        /**
         * @brief Construct a new Parser object
         *
         * @param tokens
         */
        Parser(std::vector<Token> tokens);
    };
}