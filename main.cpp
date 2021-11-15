#include <iostream>
#include <fstream>
#include <sstream>
#include "scanner.hpp"

std::string readFileIntoString (std::string);
void runFile (std::string);
void runPrompt ();

int main (int argc, char** argv) {
    if (argc > 1)
        std::cout << "Usage: loxpp [script]\n";
    else if (argc == 1) {
        std::string inp (argv[0]);
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
    lox::run(str);
}

void runPrompt () {
    std::string s;
    while (true) {
        getline(std::cin, s);
        if (s == "") {
            break;
        }
        lox::run(s);
    }
}

