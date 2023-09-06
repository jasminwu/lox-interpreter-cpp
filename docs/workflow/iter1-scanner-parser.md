# Iteration 1 Overview
During the first iteration of this project, we will make the scanner and the parser for this interpreter.

If the executable is run with an argument, the interpreter will run the whole file.
If the executable is run without an argument, then it will read user-input line by line from the console.

"Running" the source code / single line of source code consists of 3 steps:
**Scanning** - consumes *source code* and returns a list of *token objects*
**Parsing** - turns the list of *token objects* into a *syntax tree*
**Interpreting** - executes the *syntax tree* (deal with this in later iterations)

# File Setup
```
lox-interpreter-cpp
├─── src                           (contains class implementations and main)
│    ├── main.cpp                  ** entry point **
│    ├── Token.cpp              
│    ├── Scanner.cpp
│    └── Parser.cpp
├─── include
│    └── lox                       (contains class declarations)
│        ├── Token.hpp
│        ├── TokenType.hpp         *just a very basic enum class*
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
Everything written for the interpreter should be in the Lox namespace.

```cpp
namespace Lox
{
...
}
```
# Classes
More details should be given in the `.hpp` files.
## Lox
This class should never be instantiated. Only static members.
```cpp
// class declaration for the Lox Class
class Lox {
public:
     // one of these methods is called depending on the number of arguments when running the executable
     static void runFile(std::string source);
     static void runPrompt();

     // this calls the scanner -> parser -> interpreter
     static void run(std::string source); 

     // true if an error occurs during runtime
     static bool hadError;
private: 
     // handles errors and error reporting
     static void error(int line, std::string message);
     static void report(int line, std::string where, std::string message);
};
```

## TokenType
This is just an enum class. There will only be a `.hpp` file for this in `./include/lox`.
```cpp
enum class TokenType {
     LEFT_PAREN,
     RIGHT_PAREN,
     LEFT_BRACE,
     ...
};
```

## Tokens
We want the scanner to output a list of Token instances.
```cpp
class Token {
public:
     // variables
     TokenType type;
     std::string lexeme;
     std::any literal;
     int line;

     // constructor
     Token(TokenType type, std::string lexeme, std::any literal, int line);
};
```

## Scanner
In file mode, one scanner instance is created for the whole file.
In prompt mode, a new scanner instance will be made for each prompt.
```cpp
class Scanner {
public:
     Scanner(std::string source);
     std::vector<Token> scanTokens();
private:
     std::string source;           // the input
     std::vector<Token> tokens;    // the output

     // TODO: add any other methods / variables to assist in scanning
     // it is probably advised to follow the book
     // you can use regex if you want to right
};
```

## Parser
### Implementing the AST
```cpp
// Expr.hpp
abstract class Expr {
public:

     template<typename R>
     abstract class Visitor<R> {
          virtual R visit(const Binary& expr);
          virtual R visit(const Unary& expr);
          virtual R visit(const Grouping& expr);
          virtual R visit(const Literal& expr);
     };

     // generic visitor acceptor
     template<typename R> // what the actual fuck
     R accept(ExprVisitor visitor) {
          return visitor.visit(this); // check this out
     };

     // ALSO PUT GETTERS AND SETTERS HERE
     virtual std::unique_ptr<lox::Expr> getLeftExpr();
     virtual std::unique_ptr<lox::Expr> getRightExpr();
     virtual lox::Token getOper();

private:
     // all the members are here
     // pick and choose out of these depending on which derived class it is
     // these are like left and right pointers in a Binary Tree
     std::unique_ptr<lox::Expr> leftExpr_;
     std::unique_ptr<lox::Expr> rightExpr_;
     lox::Token oper;
};
```

Here are the subclasses of this Expr interface:
```cpp
class Binary : public Expr;
class Unary : public Expr;
class Grouping : public Expr;
class Literal : public Expr;
```

### Visitors
Everytime we want to make a new function that we can call on any type of expression, we implement this ExprVisitor interface with a certain type.

**Example Usage**
A function that returns the height of the AST
```cpp
// idk if this works i literally learnt visitor pattern 30 mins ago
// TEST THIS OUT
class ASTHeight : public ExprVisitor<int> {
     int visit(Binary& expr) override {
          auto visitorInstance = ASTHeight();
          return 1 + max(
               expr.getLeftExpr().accept(visitorInstance),
               expr.getRightExpr().accept(visitorInstance),
          );
     }
     int visit(Unary& expr) override {
          auto visitor = ASTHeight();
          return 1 + expr.getRightExpr().accept(visitorInstance);
     }
     int visit(Literal& expr) override {
          return 1;
     }
     int visit(Grouping& expr) override {
          return 1 + expr.getInnerExpr().accept(visitorInstance);
     }
};
```

### File Organisation
Ask Yankai

Templates are weird and problematic. Apparently you can't separate template class declarations and implementations like you can with non template stuff.

I think we will have to use tpp files and include them at the bottom of the hpp files.

Anyway this is my guess of how we should implement this
**Expr.hpp**
```cpp
#pragma once
#include <variant>
#include <string>

abstract class Expr {
     //...
}

// directly include implementation
#include "lox/Expr/Expr.tpp"
```




## Interpreter
We will deal with the rest in iteration 2.