// Instead of using Lox::Scanner to generate input for our Parser for our test
// we manually create our own vectors of tokens

/*
auto testTokens1 = new std::vector<Token>();
testTokens.push_back(Token(LEFT_PAREN, "(", NULL, 0));
*/

#include "catch2/catch.hpp"

TEST_CASE("Does math work in Parser_test.cpp?") {
    CHECK((1 + 1) == 2);
    CHECK((2 + 2) == 4);
}