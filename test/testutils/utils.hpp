#include <vector>
#include <string>

#include "lox/Lox.hpp"
#include "lox/Scanner.hpp"
#include "lox/Token.hpp"
#include "lox/TokenType.hpp"
#include "lox/Parser.hpp"

// Implement all helper functions here as static functions

namespace lox
{
namespace test
{

// function prototypes ////////////////////////////////////////////////////
static bool ReturnsTrueAlways();
static bool TokenListsEqual(std::vector<Token> a, std::vector<Token> b);

// function definitions ///////////////////////////////////////////////////
static bool ReturnsTrueAlways() {
    return true;
}

static bool TokenListsEqual(std::vector<Token> a, std::vector<Token> b) {
    if (a.size() != b.size()) return false;

    for (auto ita = a.begin(), itb = b.begin(); ita != a.end(); ++ita, ++itb) {
        if (*ita != *itb) return false; // to be operator overloaded
    }
    return true;
}

}
}