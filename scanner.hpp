//
// Created by sutirtha8623 on 4/25/21.
//

#ifndef LOXPP_SCANNER_HPP
#define LOXPP_SCANNER_HPP

#include "token.hpp"
#include <vector>
#include <string>

namespace lox {
    class Scanner {
        std::string source;
        std::vector<Token> tokens;

        int start = 0;
        int current = 0;
        int line = 1;

    public:
        explicit Scanner(std::string& s) : source(s) {}

        std::vector<Token>& scanTokens ();
        void scanToken ();
        bool isAtEnd ();
        char advance ();
        void addToken (TokenType);
    };

}
#endif //LOXPP_SCANNER_HPP
