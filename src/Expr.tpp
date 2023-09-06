#include <memory>

#include "lox/Expr.hpp"
#include "lox/Token.hpp"

namespace lox 
{

// BINARY EXPRESSIONS
Binary::Binary(
    std::unique_ptr<Expr> left,
    Token oper, 
    std::unique_ptr<Expr> right
) : Expr(std::move(left), std::move(right), nullptr, Token(), Token())
{
    leftExpr_ = std::move(left);
    oper_ = oper;
    rightExpr_ = std::move(right);
}

// UNARY EXPRESSIONS
Unary::Unary(
    Token oper, 
    std::unique_ptr<Expr> right
) : Expr(nullptr, std::move(right), nullptr, oper, Token())
{
    oper_ = oper;
    rightExpr_ = std::move(right);
}

// GROUPING EXPRESSIONS
Grouping::Grouping(
    std::unique_ptr<Expr> expr
) : Expr(nullptr, nullptr, std::move(expr), Token(), Token())
{
    innerExpr_ = std::move(expr);
}

// LITERAL EXPRESSIONS
Literal::Literal(
    Token liter
) : Expr(nullptr, nullptr, nullptr, Token(), liter)
{
    value_ = liter;
}

}