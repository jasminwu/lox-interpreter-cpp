#include "lox/Expr.hpp"

namespace lox {
    Binary::Binary(Expr* left, lox::Token operatorToken, Expr* right)
        : left_(left), operatorToken_(operatorToken), right_(right) {}

    Grouping::Grouping(Expr& expression) : expression_(expression){};

    Literal::Literal(lox::LiteralType value) : value_(value) {}

    Unary::Unary(Token operator_name, Expr& right)
        : operator_name_(operator_name), right_(right) {}
}
