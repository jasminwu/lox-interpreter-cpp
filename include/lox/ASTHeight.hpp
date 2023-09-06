#include "lox/Expr.hpp"

namespace lox
{

class ASTHeight : ExprVisitor<int> {
    int visit(Binary &expr) override;
    int visit(Unary &expr) override;
    int visit(Literal &expr) override;
    int visit(Grouping &expr) override;
};

}
