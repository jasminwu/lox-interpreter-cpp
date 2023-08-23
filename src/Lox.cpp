#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include "lox/Lox.hpp"
#include "lox/Scanner.hpp"
#include "lox/Token.hpp"
#include "lox/TokenType.hpp"
#include "lox/Parser.hpp"   

#include "color/colormod.hpp"
#include "color/color.hpp"

namespace lox 
{

void Lox::runFile(std::string path) {
    std::ifstream inputFile(path);
    std::stringstream buffer;
    buffer << inputFile.rdbuf();
    run(buffer.str());
    inputFile.close();
}

void Lox::runPrompt() {
    return;
}

void Lox::run(std::string source) {
    // currently just prints the source to ensure that it is currectly inputted
    std::cerr << lgray_f << "Printing source code:\n";
    std::cerr << dgray_f << source;
    std::cerr << lgray_f << "\nEnd of printing source code\n" << reset;

    // TODO: Run the source code

    return;
}

void Lox::error(int line, std::string message) {
    return;
}

void Lox::report(int line, std::string where, std::string message) {
    return;
}

}