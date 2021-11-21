#include <iostream>
#include <fstream>
#include <sstream>
#include "scanner.hpp"
#include "error.hpp"

std::string readFileIntoString (std::string);
void runFile (std::string);
void runPrompt ();
void run (std::string);

int main (int argc, char** argv) {
    if (argc > 2)
        std::cout << "Usage: loxpp [script]\n";
    else if (argc == 2) {
        std::string inp (argv[1]);
        runFile(inp);
    } else
        runPrompt();
}

std::string readFileIntoString (std::string fileName) {
    std::ifstream input_file(fileName);
    std::ostringstream osstr;
    osstr << input_file.rdbuf();
    return osstr.str();
}

void runFile (std::string path) {
    std::string str = readFileIntoString(path);
    run(str);
}

void runPrompt () {
    std::string s;
    while (true) {
        std::cout << "> ";
        if (!getline(std::cin, s)) {
            std::cout << "\n";
            break;
        }
        run(s);
    }
}

void run (std::string s) {
    lox::Scanner scanner = lox::Scanner(s);
    std::vector<lox::Token> tokens = scanner.scanTokens();

    for (lox::Token token : tokens) {
        std::cout << token.toString() << "\n";
    }
}