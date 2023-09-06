#pragma once

#include <string>
#include <variant>

namespace lox {

    typedef std::variant<std::monostate, double, bool, std::string> LiteralType;

}