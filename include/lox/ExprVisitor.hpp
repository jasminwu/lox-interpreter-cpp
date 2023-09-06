#pragma once

#include "lox/Expr.hpp"

namespace lox 
{

// Forward declarations for Expr subclasses
class Binary;
class Grouping;
class Literal;
class Unary;

// visitor interface
template<typename T>
class ExprVisitor {
public:
    virtual T visit(Binary& expr);
    virtual T visit(Grouping& expr);
    virtual T visit(Literal& expr);
    virtual T visit(Unary& expr);
};

}