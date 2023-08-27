#include "lox/Token.hpp"

#include <sstream>
#include <string>
#include <variant>
#include <vector>

#include "lox/TokenType.hpp"

namespace lox {
    Token::Token(lox::TokenType type, std::string lexeme, lox::Literal literal,
                 int line)
        : type_(type), lexeme_(lexeme), literal_(literal), line_(line){};

    std::string Token::literalToString(const lox::Literal& literal) {
        std::ostringstream output_str_stream;

        std::visit(
            [&](auto&& arg) {
                if constexpr (std::is_same_v<decltype(arg), double> ||
                              std::is_same_v<decltype(arg), bool>) {
                    output_str_stream << std::to_string(arg);
                } else if constexpr (std::is_same_v<decltype(arg),
                                                    std::monostate>) {
                    output_str_stream << "null";
                } else if constexpr (std::is_same_v<decltype(arg),
                                                    std::string>) {
                    output_str_stream << arg;
                }
            },
            literal);

        return output_str_stream.str();
    }

    std::string Token::toString() {
        return tokenTypes_[type_] + " " + lexeme_ + " " +
               literalToString(literal_);
    }

    bool operator==(Token const a, Token const b) {
        return a.lexeme_ == b.lexeme_ && a.line_ == b.line_ &&
               a.type_ == b.type_;
    }

    bool operator!=(Token const a, Token const b) { return !(a == b); }
}