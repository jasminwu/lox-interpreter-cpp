#include <memory>

#include "lox/Expr.hpp"
#include "lox/ExprType.hpp"
#include "lox/Token.hpp"

namespace lox 
{

// BINARY EXPRESSIONS
Binary::Binary(
    std::shared_ptr<Expr> left,
    Token oper, 
    std::shared_ptr<Expr> right
) : Expr(left, right, nullptr, Token(), Token(), ExprType::BINARY)
{
    leftExpr_ = left;
    oper_ = oper;
    rightExpr_ = right;
    type_ = ExprType::BINARY;
}

// UNARY EXPRESSIONS
Unary::Unary(
    Token oper, 
    std::shared_ptr<Expr> right
) : Expr(nullptr, right, nullptr, oper, Token(), ExprType::UNARY)
{
    oper_ = oper;
    rightExpr_ = right;
    type_ = ExprType::UNARY;
}

// GROUPING EXPRESSIONS
Grouping::Grouping(
    std::shared_ptr<Expr> expr
) : Expr(nullptr, nullptr, expr, Token(), Token(), ExprType::GROUPING)
{
    innerExpr_ = expr;
    type_ = ExprType::GROUPING;
}

// LITERAL EXPRESSIONS
Literal::Literal(
    Token liter
) : Expr(nullptr, nullptr, nullptr, Token(), liter, ExprType::LITERAL)
{
    value_ = liter;
    type_ = ExprType::LITERAL;
}

}