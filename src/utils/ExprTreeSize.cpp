#include <lox/Expr.hpp>
#include <lox/utils/ExprTreeSize.hpp>

namespace lox
{

void ExprTreeSize::visit(Binary &expr) {
    ExprTreeSize l; expr.getLeftExpr()->accept(l);
    ExprTreeSize r; expr.getLeftExpr()->accept(r);

    s_ = 1 + l.s_ + r.s_;
}

void ExprTreeSize::visit(Unary &expr) {
    ExprTreeSize v; expr.getRightExpr()->accept(v);
    s_ = 1 + v.s_;
}

void ExprTreeSize::visit(Literal &expr) {
    s_ = 1;
}

void ExprTreeSize::visit(Grouping &expr) {
    ExprTreeSize v; expr.getInnerExpr()->accept(v);
    s_ = 1 + v.s_;
}

}