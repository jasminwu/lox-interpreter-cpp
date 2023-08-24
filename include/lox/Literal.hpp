#pragma once

#include <variant>
#include <string>

namespace lox
{

typedef std::variant<std::monostate, double, bool, std::string> Literal;

}