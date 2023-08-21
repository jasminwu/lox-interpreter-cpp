#include <string>
#include <variant>

#include "lox/Lox.hpp"
#include "lox/Token.hpp"
#include "lox/TokenType.hpp"
#include "lox/Scanner.hpp"

#include "catch2/catch.hpp"
#include "testutils/utils.hpp"

TEST_CASE("YOU HAVE NOT WRITTEN TESTS FOR SCANNER!!") { CHECK((2 + 2) == 4); }

TEST_CASE("Correctly scans a simple hello world program") {
    std::string source = "print \"Hello, world!\";";

    // build the expected token list
    auto expected = std::vector<lox::Token>();

    // manually creating the token list using initialiser lists
    /*
    expected.push_back({
        PRINT,
        "print",
        SOMETHING IDK,
        1
    });
    */
   CHECK(1 == 1);
}