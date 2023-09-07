#pragma once

#include <variant>
#include <memory>

#include "lox/Token.hpp"
#include "lox/ExprType.hpp"

namespace lox 
{

// Forward declarations for Expr subclasses
class Binary;
class Grouping;
class Literal;
class Unary;

// interface for all visitors
class ExprVisitor {
public:
    virtual void visit(Binary& expr) = 0;
    virtual void visit(Grouping& expr) = 0;
    virtual void visit(Literal& expr) = 0;
    virtual void visit(Unary& expr) = 0;
};

// expression interface
class Expr {
protected: 
    std::shared_ptr<Expr> leftExpr_;
    std::shared_ptr<Expr> rightExpr_;
    std::shared_ptr<Expr> innerExpr_;
    Token oper_;
    Token value_; // literal or identifier
    ExprType type_;

public:
    // constructor and destructor
    Expr() {}

    virtual ~Expr() {}

    virtual void accept(ExprVisitor& visitor) = 0;

};

// Declare subclasses of Expr

class Binary : public Expr {
private:
    std::shared_ptr<Expr> leftExpr_;
    Token oper_;
    std::shared_ptr<Expr> rightExpr_;

public:
    Binary(std::shared_ptr<Expr> left, Token oper, std::shared_ptr<Expr> right);

    // visitor acceptor
    void accept(ExprVisitor& visitor) override {
        return visitor.visit(*this);
    };

    // getters and setters
    std::shared_ptr<Expr> getLeftExpr() {
        return leftExpr_;
    }
    std::shared_ptr<Expr> getRightExpr() {
        return rightExpr_;
    }
    Token getOper() {
        return oper_;
    }
};

class Unary : public Expr {
private:
    Token oper_;
    std::shared_ptr<Expr> rightExpr_;
    
public:
    Unary(Token operator_name, std::shared_ptr<Expr> right);

    // visitor acceptor
    void accept(ExprVisitor& visitor) override {
        return visitor.visit(*this);
    };

    // getters and setters
    std::shared_ptr<Expr> getRightExpr() {
        return rightExpr_;
    }
    Token getOper() {
        return oper_;
    }
};

class Grouping : public Expr {
private:
    std::shared_ptr<Expr> innerExpr_;
    
public:
    Grouping(std::shared_ptr<Expr> expr);

    // visitor acceptor
    void accept(ExprVisitor& visitor) override {
        return visitor.visit(*this);
    };

    // getters and setters
    std::shared_ptr<Expr> getInnerExpr() {
        return innerExpr_;
    }
};

class Literal : public Expr {
private:
    Token value_;
    
public:
    Literal(Token liter);

    // visitor acceptor
    void accept(ExprVisitor& visitor) override {
        return visitor.visit(*this);
    };

    // getters and setters
    Token getValue() {
        return value_;
    }
};

}