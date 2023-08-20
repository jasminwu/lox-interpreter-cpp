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
    test/Parser.test.cpp 
    test/Scanner.test.cpp
)

# Create the main executable
add_executable(app
    ${SOURCES}
    src/main.cpp
)

# Create the test executable
add_executable(testapp
    ${SOURCES}
    ${TEST_SOURCES}
    test/main.test.cpp
)

enable_testing()

# Add tests
add_test(NAME MyTest COMMAND testapp)

