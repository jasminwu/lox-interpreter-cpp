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
        1
    });
    expected.push_back({
        lox::TokenType::SEMICOLON,  
        ";",
        std::monostate(),
        1
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
        1
    });
    expected.push_back({
        lox::TokenType::EQUAL,  
        "=",
        std::monostate(),
        1
    });
    expected.push_back({
        lox::TokenType::NUMBER,  
        "10",
        10,
        1
    });
    expected.push_back({
        lox::TokenType::SEMICOLON,  
        ";",
        std::monostate(),
        1
    });

   CHECK(lox::test::TokenListsEqual(expected, received));
}

TEST_CASE("Multiple lines, plus minus multiply divide") {
    
    std::string source = "var a = 10;\na + 4.2;\na - 2;\na * a;\n a / 2;";

    auto scannerObj = lox::Scanner(source);
    auto received = scannerObj.scanTokens();
    auto expected = std::vector<lox::Token>();

    // line 1
    expected.push_back({
        lox::TokenType::VAR,  
        "var",
        std::monostate(),
        1
    });
    expected.push_back({
        lox::TokenType::IDENTIFIER,  
        "a",
        std::monostate(),
        1
    });
    expected.push_back({
        lox::TokenType::EQUAL,  
        "=",
        std::monostate(),
        1
    });
    expected.push_back({
        lox::TokenType::NUMBER,  
        "10",
        10,
        1
    });
    expected.push_back({
        lox::TokenType::SEMICOLON,  
        ";",
        std::monostate(),
        1
    });

    // line 2
    expected.push_back({
        lox::TokenType::IDENTIFIER,  
        "a",
        std::monostate(),
        2
    });
    expected.push_back({
        lox::TokenType::PLUS,  
        "+",
        std::monostate(),
        2
    });
    expected.push_back({
        lox::TokenType::NUMBER,  
        "4.2",
        4.2,
        2
    });
    expected.push_back({
        lox::TokenType::SEMICOLON,  
        ";",
        std::monostate(),
        1
    });

    // line 3
    expected.push_back({
        lox::TokenType::IDENTIFIER,  
        "a",
        std::monostate(),
        3
    });
    expected.push_back({
        lox::TokenType::MINUS,  
        "-",
        std::monostate(),
        3
    });
    expected.push_back({
        lox::TokenType::NUMBER,  
        "2",
        2,
        3
    });
    expected.push_back({
        lox::TokenType::SEMICOLON,  
        ";",
        std::monostate(),
        3
    });

    // line 4
    expected.push_back({
        lox::TokenType::IDENTIFIER,  
        "a",
        std::monostate(),
        4
    });
    expected.push_back({
        lox::TokenType::STAR,
        "*",
        std::monostate(),
        4
    });
    expected.push_back({
        lox::TokenType::IDENTIFIER,  
        "a",
        std::monostate(),
        4
    });
    expected.push_back({
        lox::TokenType::SEMICOLON,  
        ";",
        std::monostate(),
        4
    });

    // line 5
    expected.push_back({
        lox::TokenType::IDENTIFIER,  
        "a",
        std::monostate(),
        5
    });
    expected.push_back({
        lox::TokenType::SLASH,
        "/",
        std::monostate(),
        5
    });
    expected.push_back({
        lox::TokenType::NUMBER,  
        "2",
        2,
        5
    });
    expected.push_back({
        lox::TokenType::SEMICOLON,  
        ";",
        std::monostate(),
        5
    });

   CHECK(lox::test::TokenListsEqual(expected, received));
}

TEST_CASE("Negative numbers") {
    
    std::string source = "john = -6.9;";

    auto scannerObj = lox::Scanner(source);
    auto received = scannerObj.scanTokens();
    auto expected = std::vector<lox::Token>();

    expected.push_back({
        lox::TokenType::IDENTIFIER,  
        "john",
        std::monostate(),
        1
    });
    expected.push_back({
        lox::TokenType::EQUAL,  
        "=",
        std::monostate(),
        1
    });
    expected.push_back({
        lox::TokenType::MINUS,  
        "-",
        std::monostate(),
        1
    });
    expected.push_back({
        lox::TokenType::NUMBER,  
        "6.9",
        6.9,
        1
    });
    expected.push_back({
        lox::TokenType::SEMICOLON,  
        ";",
        std::monostate(),
        1
    });

   CHECK(lox::test::TokenListsEqual(expected, received));
}

TEST_CASE("Equality of negative numbers") {
    
    std::string source = "4 == -6.9;";

    auto scannerObj = lox::Scanner(source);
    auto received = scannerObj.scanTokens();
    auto expected = std::vector<lox::Token>();

    expected.push_back({
        lox::TokenType::IDENTIFIER,  
        "4",
        4,
        1
    });
    expected.push_back({
        lox::TokenType::EQUAL_EQUAL,  
        "==",
        std::monostate(),
        1
    });
    expected.push_back({
        lox::TokenType::MINUS,  
        "-",
        std::monostate(),
        1
    });
    expected.push_back({
        lox::TokenType::NUMBER,  
        "6.9",
        6.9,
        1
    });
    expected.push_back({
        lox::TokenType::SEMICOLON,  
        ";",
        std::monostate(),
        1
    });

   CHECK(lox::test::TokenListsEqual(expected, received));
}