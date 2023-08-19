cmake_minimum_required(VERSION 3.10)  # Minimum CMake version required
project(lox-interpreter-cpp)                   # Name of the project


file(GLOB SOURCES
    "src/*.cpp"
    "src/*.hpp"
)

add_executable(lox-interpreter-cpp ${SOURCES})

