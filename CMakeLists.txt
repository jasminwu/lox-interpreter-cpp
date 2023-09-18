cmake_minimum_required(VERSION 3.16)  # Minimum CMake version required
project(lox-interpreter-cpp)                   # Name of the project

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


include_directories(include)
include_directories(src)
include_directories(test)

file(GLOB SOURCES
    src/Lox.cpp
    src/Parser.cpp
    src/Scanner.cpp
    src/Token.cpp
    src/Expr.cpp
)

file(GLOB UTIL_SOURCES
    src/utils/ExprTreeHeight.cpp 
    src/utils/ExprTreePrinter.cpp
    src/utils/ExprTreeSize.cpp
)

file(GLOB TEST_SOURCES
    test/tests_main.cpp
    test/AlwaysTrue.cpp
    test/Lox_test.cpp 
    test/Parser_test.cpp 
    test/Scanner_test.cpp
)


############## I DONT THINK YOU NEED TO MODIFY BELOW THIS LINE ################
# Create the main executable
add_executable(app
    ${SOURCES}
    ${UTIL_SOURCES}
    src/main.cpp
)
# TESTING 
enable_testing()
# Test Executable
add_executable(testapp
    ${SOURCES}
    ${UTIL_SOURCES}
    ${TEST_SOURCES}
)
add_test(NAME COMPLETE_TEST COMMAND testapp)