cmake_minimum_required(VERSION 3.10)  # Minimum CMake version required
project(lox-interpreter-cpp)                   # Name of the project

file(GLOB SOURCES
    "src/*.cpp"
    "src/*.hpp"
)

file(GLOB TEST_SOURCES
    "src/tests/*.cpp"
)

# Create the main executable
add_executable(app ${SOURCES})

# Create the test executable
add_executable(testapp ${TEST_SOURCES} ${SOURCES})

enable_testing()

# Add tests
add_test(NAME MyTest COMMAND testapp)

