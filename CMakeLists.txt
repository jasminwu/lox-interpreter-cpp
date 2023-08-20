cmake_minimum_required(VERSION 3.16)  # Minimum CMake version required
project(lox-interpreter-cpp)                   # Name of the project

include_directories(include, src, test, include/lox)

file(GLOB SOURCES
    "src/*.cpp"
)

file(GLOB TEST_SOURCES
    "test/*.cpp"
)

# Create the main executable
add_executable(app 
    ${SOURCES}
)

# Create the test executable
add_executable(testapp 
    ${TEST_SOURCES} ${SOURCES}
)

enable_testing()

# Add tests
add_test(NAME MyTest COMMAND testapp)

