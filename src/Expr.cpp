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
) : leftExpr_(left), oper_(oper), rightExpr_(right) {}

// UNARY EXPRESSIONS
Unary::Unary(
    Token oper, 
    std::shared_ptr<Expr> right
) : oper_(oper), rightExpr_(right) {}

// GROUPING EXPRESSIONS
Grouping::Grouping(
    std::shared_ptr<Expr> expr
) : innerExpr_(expr) {}

// LITERAL EXPRESSIONS
Literal::Literal(
    Token literal
) : value_(literal) {}

}