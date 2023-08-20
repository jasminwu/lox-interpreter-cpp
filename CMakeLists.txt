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
    test/tests_main.cpp
    test/intentionallyBrokenTest.cpp
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
add_executable(testapp
    ${SOURCES}
    ${TEST_SOURCES}
)
add_test(NAME COMPLETE_TEST COMMAND testapp)