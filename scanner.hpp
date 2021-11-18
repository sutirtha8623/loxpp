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

    public:
        explicit Scanner(std::string& s) : source(s) {}

        std::vector<Token> scanTokens ();
    };

}
#endif //LOXPP_SCANNER_HPP
