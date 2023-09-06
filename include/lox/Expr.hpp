#pragma once

#include <variant>
#include <memory>

#include "lox/Token.hpp"
#include "lox/ExprVisitor.hpp"


namespace lox 
{

// Forward declarations for Expr subclasses
class Binary;
class Grouping;
class Literal;
class Unary;

class Expr {
public:
    // constructor and destructor
    Expr(
        std::unique_ptr<Expr> leftExpr,
        std::unique_ptr<Expr> rightExpr,
        std::unique_ptr<Expr> innerExpr,
        Token oper,
        Token value
    ) : 
    leftExpr_(std::move(leftExpr)),
    rightExpr_(std::move(rightExpr)),
    innerExpr_(std::move(innerExpr)),
    oper_(oper),
    value_(value) {
        leftExpr_ = std::move(leftExpr);
        rightExpr_ = std::move(rightExpr);
        innerExpr_ = std::move(innerExpr);
        oper_ = oper;
        value_ = value;
    }

    virtual ~Expr() {}

    template<typename T>
    virtual T accept(ExprVisitor<T> visitor);

protected: 
    std::unique_ptr<Expr> leftExpr_;
    std::unique_ptr<Expr> rightExpr_;
    std::unique_ptr<Expr> innerExpr_;
    Token oper_;
    Token value_; // literal or identifier
};

// Declare subclasses of Expr

class Binary : public Expr {
public:
    Binary(std::unique_ptr<Expr> left, Token oper, std::unique_ptr<Expr> right);
    // visitor acceptor
    template<typename T>
    T accept(ExprVisitor<T>& visitor) {
        return visitor.visit(*this);
    };

    // getters and setters
    virtual std::unique_ptr<Expr> getLeftExpr() {
        return std::move(leftExpr_);
    }
    virtual std::unique_ptr<Expr> getRightExpr() {
        return std::move(rightExpr_);
    }
    virtual Token getOper() {
        return oper_;
    }
};

class Unary : public Expr {
public:
    Unary(Token operator_name, std::unique_ptr<Expr> right);
    // visitor acceptor
    template<typename T>
    T accept(ExprVisitor<T>& visitor) {
        return visitor.visit(*this);
    };

    // getters and setters
    virtual std::unique_ptr<Expr> getRightExpr() {
        return std::move(rightExpr_);
    }
    virtual Token getOper() {
        return oper_;
    }
};

class Grouping : public Expr {
public:
    Grouping(std::unique_ptr<Expr> expr);
    // visitor acceptor
    template<typename T>
    T accept(ExprVisitor<T>& visitor) {
        return visitor.visit(*this);
    };

    // getters and setters
    virtual std::unique_ptr<Expr> getInnerExpr() {
        return std::move(innerExpr_);
    }
};

class Literal : public Expr {
public:
    Literal(Token liter);
    // visitor acceptor
    template<typename T>
    T accept(ExprVisitor<T>& visitor) {
        return visitor.visit(*this);
    };

    // getters and setters
    virtual Token getValue() {
        return value_;
    }
};

}

#include "Expr.tpp"