#include <algorithm>

#include "lox/Expr.hpp"
#include "lox/ASTHeight.hpp"

namespace lox
{

void ASTHeight::visit(Binary &expr) {
    ASTHeight l; expr.getLeftExpr()->accept(l);
    ASTHeight r; expr.getRightExpr()->accept(r);
    h_ = 1 + std::max(l.h_, r.h_); 
}

void ASTHeight::visit(Unary &expr) {
    ASTHeight r; expr.getRightExpr()->accept(r);
    h_ = 1 + r.h_;
}

void ASTHeight::visit(Literal &expr) {
    h_ = 1;
}

void ASTHeight::visit(Grouping &expr) {
    ASTHeight i; expr.getInnerExpr()->accept(i);
    h_ = 1 + i.h_;
}

}