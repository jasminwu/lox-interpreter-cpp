#pragma once

#include <string>
#include <vector>

#include "Token.hpp"

namespace lox {
    class Scanner {
    private:
        std::string source_;
        std::vector<lox::Token> tokens;

    public:
        // Constructor
        Scanner(std::string source);
    };
}