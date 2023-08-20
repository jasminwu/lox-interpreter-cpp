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
├─── src                        (contains class implementations and main)
│    ├── main.cpp               ** entry point **
│    ├── Token.cpp              
│    ├── Scanner.cpp
│    └── Parser.cpp
├─── include
│    └── lox                    (contains class declarations)
│        ├── Token.hpp
│        ├── Scanner.hpp        
│        └── Parser.hpp
└─── test
     ├── catch2
     │   └── catch.h            (the testing framework)
     ├── Scanner.test.cpp
     └── Parser.test.cpp
```
Everything written for the interpreter should be in the Lox namespace.

```cpp
namespace Lox
{
...
}
```
# Classes
## Lox

## Tokens

## Scanner

## Parser

## Interpreter
We will deal with the rest in iteration 2.