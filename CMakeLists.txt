cmake_minimum_required(VERSION 3.16)  # Minimum CMake version required
project(lox-interpreter-cpp)                   # Name of the project

include_directories(include)
include_directories(src)
include_directories(test)

file(GLOB SOURCES
    src/Lox.cpp
    src/Parser.cpp
    src/Scanner.cpp
    src/Token.cpp
)

file(GLOB TEST_SOURCES
    test/Lox_test.cpp 
    test/Parser_test.cpp 
    test/Scanner_test.cpp
)

# Create the main executable
add_executable(app
    ${SOURCES}
    src/main.cpp
)

# TESTING ######################################
enable_testing()

# Test Executables
add_executable(Lox_test
    ${SOURCES}
    test/Lox_test.cpp
)
add_test(NAME Lox_test COMMAND Lox_test)

add_executable(Scanner_test
    ${SOURCES}
    test/Scanner_test.cpp
)
add_test(NAME Scanner_test COMMAND Scanner_test)

add_executable(Parser_test
    ${SOURCES}
    test/Scanner_test.cpp
)
add_test(NAME Parser_test COMMAND Parser_test)