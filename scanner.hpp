//
// Created by sutirtha8623 on 4/25/21.
//

#ifndef LOXPP_SCANNER_HPP
#define LOXPP_SCANNER_HPP

#include "token.hpp"
#include <vector>
#include <string>
#include <memory>
#include <map>

namespace lox {
    class Scanner {
        std::string source;
        std::vector<Token> tokens;

        int start;
        int current;
        int line;

        static std::map<std::string, TokenType> keywords;

    public:
        explicit Scanner(std::string& s) : source(s) {
            start = 0;
            current = 0;
            line = 1;
        }
        ~Scanner () {}

        std::vector<Token>& scanTokens ();

        void scanToken ();

        void identifier ();
        void number ();
        void string ();
        bool match (char);

        char peek ();
        char peekNext ();
        bool isAlpha (char);
        bool isAlphaNumeric (char);
        bool isDigit (char);
        bool isAtEnd ();
        char advance ();

        void addToken (TokenType);
    };

}
#endif //LOXPP_SCANNER_HPP
