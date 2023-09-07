#pragma once

namespace lox {
    enum class ExprType {
        BINARY,
        UNARY,
        GROUPING,
        LITERAL
    };
}