#include "lox/Token.hpp"

#include <sstream>
#include <string>
#include <variant>
#include <vector>

#include "lox/TokenType.hpp"

namespace lox {

    // default constructor
    Token::Token()
        : type_(TokenType::TOKEN_EOF),
          lexeme_(""),
          literal_(std::monostate()),
          line_(0) {}

    // constructor where you can initialise members
    Token::Token(lox::TokenType type, std::string lexeme,
                 lox::LiteralType literal, int line)
        : type_(type), lexeme_(lexeme), literal_(literal), line_(line){};

    // other methods

    std::string Token::literalToString(const lox::LiteralType& literal) {
        std::ostringstream output_str_stream;

        std::visit(
            [&](auto&& arg) {
                using T = std::decay_t<decltype(arg)>;

                if constexpr (std::is_same_v<T, double> ||
                              std::is_same_v<T, bool>) {
                    output_str_stream << std::to_string(arg);
                } else if constexpr (std::is_same_v<T, std::monostate>) {
                    output_str_stream << "null";
                } else if constexpr (std::is_same_v<T, std::string>) {
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

    lox::TokenType Token::getTokenType() { return type_; }

    bool operator==(Token const a, Token const b) {
        return a.lexeme_ == b.lexeme_ && a.line_ == b.line_ &&
               a.type_ == b.type_;
    }

    bool operator!=(Token const a, Token const b) { return !(a == b); }

}