#include <memory>

#include "lox/Expr.hpp"
#include "lox/ExprType.hpp"
#include "lox/Token.hpp"

namespace lox 
{

// BINARY EXPRESSIONS
Binary::Binary(
    std::shared_ptr<Expr> leftExpr,
    Token operToken, 
    std::shared_ptr<Expr> rightExpr
) : leftExpr_(leftExpr), operToken_(operToken), rightExpr_(rightExpr) {}

// UNARY EXPRESSIONS
Unary::Unary(
    Token operToken, 
    std::shared_ptr<Expr> rightExpr
) : operToken_(operToken), rightExpr_(rightExpr) {}

// GROUPING EXPRESSIONS
Grouping::Grouping(
    std::shared_ptr<Expr> innerExpr
) : innerExpr_(innerExpr) {}

// LITERAL EXPRESSIONS
Literal::Literal(
    Token literalToken
) : literalToken_(literalToken) {}

}