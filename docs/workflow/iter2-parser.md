# Iteration 2 Overview
In this iteration we will implement the classes for the AST, and also start with using recursive descent parsing in order to parse our lexemes into an AST.

In this iteration we will only handle Expr parsing. We will leave Stmts till later.


## The Lox Grammar for Expressions
```cpp
//# LOWEST PRECEDENCE
expression  ::= equality;
equality    ::= comparison (("!=" | "==") comparison)*;
comparison  ::= term ((">" | ">=" | "<" | "<=") term)*;
term        ::= factor (("-" | "+") factor)*;
factor      ::= factor ("/" | "*") unary | unary; # left associative
unary       ::= ("!" | "-") unary | primary;      # right associative
primary     ::= NUMBER | STRING | "true" | "false" | "nul " | "(" expression ")" | IDENTIFIER;
//# HIGHEST PRECEDENCE

```

## Expr Class and ExprVisitor
The AST is stored in a tree structure. Each node contains smart-pointers to its children.
```cpp
// kinda like this
struct node { // this class isn't actually used // this is how BINARY will work
    std::shared_ptr<node> left;
    std::shared_ptr<node> right;
}
```

All node classes are derived from the abstract class Expr.

The Expr class has no "children" member variables. Those are for the subclasses to declare themselves.

```cpp
// Expr.hpp
class Expr {
public:
    // visitor acceptor
    virtual void accept(ExprVisitor& visitor) {
        return visitor.visit(this); // check this out
    };
};
```

Here are the subclasses of this Expr interface currently in this iteration.

```cpp
class Binary : public Expr;
class Unary : public Expr;
class Grouping : public Expr;
class Literal : public Expr;
// more may be added later
```
All objects instantiated from these classes are nodes in the AST.

## Visitors
Everytime we want to make a new function that we can call on any type of expression, we implement this ExprVisitor interface with a certain additional member variable.

```cpp
// in Expr.hpp above the declaration of the Expr class
class ExprVisitor {
    virtual void visit(const Binary& expr);
    virtual void visit(const Unary& expr);
    virtual void visit(const Grouping& expr);
    virtual void visit(const Literal& expr);
};

/// class Expr { ...

```

Eventually we will be making another type of visitor interface, a StmtVisitor.

The interpreter will contain a visitor implementation which inherits from both the ExprVisitor and StmtVisitor interfaces.

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

## Recursive Descent Parsing

### The Parser Class
The parser class contains a list of Tokens (provided by the scanner). It iterates through the list.
```cpp
class Parser {
    std::vector<lox::Token>             tokens_;  // list of tokens
    std::vector<lox::Token>::iterator   current_; // iterator on list

    // constructor initializer list
    Parser(std::vector<lox::Token> tokens) : tokens_(tokens){};
};
```
The parser will contain several recursive methods.

Each of these methods returns an AST node (Expr object).





## File Organisation
Both declarations of Expr and ExprVisitor are stored in `Expr.hpp`

```
lox-interpreter-cpp
├─── src                           (contains class implementations and main)
│    ├── main.cpp                  ** entry point **
│    ├── Token.cpp              
│    ├── Scanner.cpp
│    ├── Expr.cpp       [CONTAINS IMPLS OF CNCRT DRVED CLASSES OF EXPR]
│    ├── ASTHeight.cpp  [CONTAINS IMPL OF EXAMPLE EXPRVSTR]
│    └── Parser.cpp
├─── include
│    └── lox                       (contains class declarations)
│        ├── Token.hpp
│        ├── TokenType.hpp         *just a very basic enum class*
│        ├── Scanner.hpp        
│        ├── Expr.hpp       [DECL OF ABS & CNCRT EXPR AND ABS EXPRVSTR CLASSES]
│        ├── ASTVHeight.hpp [DECL OF EXAMPLE EXPRVSTR]
│        ├── Scanner.hpp        
│        └── Parser.hpp
└─── test
     ├── catch2                    (testing framework)
     │   └── catch.hpp
     ├── testutils                 (utility functions for testing)
     │   └── utils.hpp             
     ├── tests_main.cpp            (entry point for tests)
     ├── Lox_test.cpp
     ├── Scanner_test.cpp
     └── Parser_test.cpp
```
