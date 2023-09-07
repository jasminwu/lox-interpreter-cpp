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