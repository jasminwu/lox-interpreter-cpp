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
public:
    // constructor and destructor
    Expr(
        std::shared_ptr<Expr> leftExpr,
        std::shared_ptr<Expr> rightExpr,
        std::shared_ptr<Expr> innerExpr,
        Token oper,
        Token value,
        ExprType type
    ) : 
    leftExpr_(leftExpr),
    rightExpr_(rightExpr),
    innerExpr_(innerExpr),
    oper_(oper),
    value_(value),
    type_(type) {
        leftExpr_ = leftExpr;
        rightExpr_ = rightExpr;
        innerExpr_ = innerExpr;
        oper_ = oper;
        value_ = value;
        type_ = type;
    }

    virtual ~Expr() {}

    virtual void accept(ExprVisitor& visitor) = 0;

protected: 
    std::shared_ptr<Expr> leftExpr_;
    std::shared_ptr<Expr> rightExpr_;
    std::shared_ptr<Expr> innerExpr_;
    Token oper_;
    Token value_; // literal or identifier
    ExprType type_;
};

// Declare subclasses of Expr

class Binary : public Expr {
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