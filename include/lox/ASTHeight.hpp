#include "lox/Expr.hpp"

namespace lox
{

class ASTHeight : public ExprVisitor {
public:
    int h_;
    void visit(Binary &expr) override;
    void visit(Unary &expr) override;
    void visit(Literal &expr) override;
    void visit(Grouping &expr) override;
};

}
