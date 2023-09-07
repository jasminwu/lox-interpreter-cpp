#include <string>

#include "lox/Expr.hpp"

namespace lox {

class ExprTreePrinter : public ExprVisitor {
public:
    void visit(Binary &expr) override;
    void visit(Unary &expr) override;
    void visit(Literal &expr) override;
    void visit(Grouping &expr) override;
};

}