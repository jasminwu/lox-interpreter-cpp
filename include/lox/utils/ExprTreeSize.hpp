#pragma once

#include <lox/Expr.hpp>

namespace lox
{

class ExprTreeSize : public ExprVisitor {
public:
    int s_;
    void visit(Binary &expr) override;
    void visit(Unary &expr) override;
    void visit(Literal &expr) override;
    void visit(Grouping &expr) override;
};

}