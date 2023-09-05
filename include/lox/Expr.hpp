#pragma once

#include <variant>

#include "lox/Token.hpp"

namespace lox {
    class Visitor;  // Forward declaration

    // Forward declarations for Expr subclasses
    class Binary;
    class Grouping;
    class Literal;
    class Unary;

    class Expr {
    public:
        // Base class for expressions
        virtual ~Expr() {
        }  // Virtual destructor to ensure proper cleanup in derived classes

        virtual void accept(Visitor& visitor) = 0;
    };

    class Visitor {
    public:
        virtual void visitBinaryExpr(const Binary& expr) = 0;
        virtual void visitGroupingExpr(const Grouping& expr) = 0;
        virtual void visitLiteralExpr(const Literal& expr) = 0;
        virtual void visitUnaryExpr(const Unary& expr) = 0;
    };

    class Binary : public Expr {
    public:
        Binary(Expr* left, lox::Token operatorToken, Expr* right);

        void accept(Visitor& visitor) override {
            visitor.visitBinaryExpr(*this);
        }

        Expr* left_;
        lox::Token operatorToken_;
        Expr* right_;
    };

    class Grouping : public Expr {
    public:
        Grouping(Expr& expression);

        void accept(Visitor& visitor) override {
            visitor.visitGroupingExpr(*this);
        }

        Expr& expression_;
    };

    class Literal : public Expr {
    public:
        Literal(lox::LiteralType value);

        void accept(Visitor& visitor) override {
            visitor.visitLiteralExpr(*this);
        }

        lox::LiteralType value_;
    };

    class Unary : public Expr {
    public:
        Unary(Token operator_name, Expr& right);

        void accept(Visitor& visitor) override {
            visitor.visitUnaryExpr(*this);
        }

        Token operator_name_;
        Expr& right_;
    };
}
