#include <string>
#include <variant>

#include "lox/Lox.hpp"
#include "lox/Token.hpp"
#include "lox/TokenType.hpp"
#include "lox/Scanner.hpp"

#include "catch2/catch.hpp"
#include "testutils/utils.hpp"

TEST_CASE("Sanity Check: empty vectors are equal") {
    auto received = std::vector<lox::Token>();
    auto expected = std::vector<lox::Token>();

   CHECK(lox::test::TokenListsEqual(expected, received));
}

TEST_CASE("Print statement with string literal") {
    std::string source = "print \"Hello, world!\";";

    // get the received token list
    auto scannerObj = lox::Scanner(source);
    auto received = scannerObj.scanTokens();

    // build the expected token list
    auto expected = std::vector<lox::Token>();

    // manually creating the token list using initialiser lists
    expected.push_back({
        lox::TokenType::PRINT,  
        "print",
        std::monostate(),
        1
    });
    expected.push_back({
        lox::TokenType::STRING,  
        "\"Hello, world!\"",
        "Hello, world!",
        2
    });
    expected.push_back({
        lox::TokenType::SEMICOLON,  
        ";",
        std::monostate(),
        3
    });

   CHECK(lox::test::TokenListsEqual(expected, received));
}

TEST_CASE("Variable declaration and initialisation") {
    std::string source = "var Jack = 10;";

    auto scannerObj = lox::Scanner(source);
    auto received = scannerObj.scanTokens();
    auto expected = std::vector<lox::Token>();

    expected.push_back({
        lox::TokenType::VAR,  
        "var",
        std::monostate(),
        1
    });
    expected.push_back({
        lox::TokenType::IDENTIFIER,  
        "Jack",
        std::monostate(),
        2
    });
    expected.push_back({
        lox::TokenType::EQUAL,  
        "=",
        std::monostate(),
        3
    });
    expected.push_back({
        lox::TokenType::NUMBER,  
        "10",
        10,
        3
    });

   CHECK(lox::test::TokenListsEqual(expected, received));
}