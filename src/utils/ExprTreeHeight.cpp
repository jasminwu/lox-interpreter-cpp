#include <algorithm>

#include "lox/Expr.hpp"
#include "lox/utils/ExprTreeHeight.hpp"

namespace lox
{

void ExprTreeHeight::visit(Binary &expr) {
    ExprTreeHeight l; expr.getLeftExpr()->accept(l);
    ExprTreeHeight r; expr.getRightExpr()->accept(r);
    h_ = 1 + std::max(l.h_, r.h_); 
}

void ExprTreeHeight::visit(Unary &expr) {
    ExprTreeHeight r; expr.getRightExpr()->accept(r);
    h_ = 1 + r.h_;
}

void ExprTreeHeight::visit(Literal &expr) {
    h_ = 1;
}

void ExprTreeHeight::visit(Grouping &expr) {
    ExprTreeHeight i; expr.getInnerExpr()->accept(i);
    h_ = 1 + i.h_;
}

}