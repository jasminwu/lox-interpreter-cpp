#include <string>
#include <variant>

#include "lox/Token.hpp"
#include "lox/TokenType.hpp"

namespace lox {
    Token::Token(lox::TokenType type, std::string lexeme, std::variant<std::monostate, int, double, std::string> literal,
                 int line)
        : type_(type), lexeme_(lexeme), literal_(literal), line_(line){};

    std::string Token::toString() { return ""; }

    // Operator Overload Implementations
    bool operator==(Token const a, Token const b) {
        return a.lexeme_ == b.lexeme_ &&
        a.line_ == b.line_ &&
        a.type_ == b.type_;
    }

    bool operator!=(Token const a, Token const b) {
        return !(a == b);
    }

}