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
        /**
         * @brief Construct a new Scanner object
         *
         * @param source - Contents of the source file in string form
         */
        Scanner(std::string source);
    };
}