#include "lox/Expr.hpp"
#include "lox/ASTHeight.hpp"

namespace lox
{

int ASTHeight::visit(Binary &expr) {
    auto visitor = ASTHeight();
    return 1 + std::max(
        expr.getLeftExpr()->accept(visitor),
        expr.getRightExpr()->accept(visitor)
    );
}

int ASTHeight::visit(Unary &expr) {
    auto visitor = ASTHeight();
    return 1 + expr.getRightExpr()->accept(visitor);
}

int ASTHeight::visit(Literal &expr) {
    return 1;
}

int ASTHeight::visit(Grouping &expr) {
    auto visitor = ASTHeight();
    return 1 + expr.getInnerExpr()->accept(visitor);
}

}