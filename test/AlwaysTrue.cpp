#include "catch2/catch.hpp"
#include "testutils/utils.hpp"

TEST_CASE("Test Always Passes") {
    CHECK((2 + 2) == 4);
}

TEST_CASE("Test also always passes") {
    CHECK(lox::test::ReturnsTrueAlways());
}