# Iteration 2 Overview
In this iteration we will implement the classes for the AST, and also start with using recursive descent parsing in order to parse our lexemes into an AST.

We will be using the Visitor Pattern to traverse the tree.

## Expr Class and ExprVisitor
```cpp
// Expr.hpp
class ExprVisitor {
    virtual void visit(const Binary& expr);
    virtual void visit(const Unary& expr);
    virtual void visit(const Grouping& expr);
    virtual void visit(const Literal& expr);
};

class Expr {
public:
    // visitor acceptor
    virtual void accept(ExprVisitor& visitor) {
        return visitor.visit(this); // check this out
    };
};
```

Here are the subclasses of this Expr interface:
```cpp
class Binary : public Expr;
class Unary : public Expr;
class Grouping : public Expr;
class Literal : public Expr;
```

## Visitors
Everytime we want to make a new function that we can call on any type of expression, we implement this ExprVisitor interface with a certain additional member variable.

#### Example Implementation of the ExprVisitor
This is an implementation of a Visitor which allows you to calculate the height of an AST.
```cpp
class ASTHeight : public ExprVisitor {
    int h_;

    void visit(Binary &expr) override {
        ASTHeight l; expr.getLeftExpr()->accept(l);
        ASTHeight r; expr.getRightExpr()->accept(r);
        h_ = 1 + std::max(l.h_, r.h_);
    }

    void visit(Unary &expr) override {
        ASTHeight r; expr.getRightExpr()->accept(r);
        h_ = 1 + r.h_;
    }

    void visit(Literal &expr) {
        h_ = 1;
    }

    void ASTHeight::visit(Grouping &expr) {
        ASTHeight i; expr.getInnerExpr()->accept(i);
        h_ = 1 + i.h_;
    }
};
```

And this is how you would use it to find the height of a AST.
```cpp
lox::Token hii = {lox::TokenType::STRING, "\"hello\"", (std::string) "hello", 2};
lox::Token fun = {lox::TokenType::NUMBER, "69", (double) 69, 2};
lox::Token opp = {lox::TokenType::PLUS, "+", std::monostate(), 2};

auto left = std::make_shared<lox::Literal>(hii);
auto right = std::make_shared<lox::Literal>(fun);
auto root = std::make_shared<lox::Binary>(left, opp, right);

lox::ASTHeight visitor;
root->accept(visitor);
std::cout << visitor.h_ << std::endl; // returns 2 (height of binary expression)

lox::ASTHeight anothervisitor;
right->accept(anothervisitor);
std::cout << anothervisitor.h_ << std::endl; // returns 1 (height of a single literal)
```

### File Organisation
We won't be using templates
