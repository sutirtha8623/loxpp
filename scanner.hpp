//
// Created by sutirtha8623 on 4/25/21.
//

#ifndef LOX___SCANNER_HPP
#define LOX___SCANNER_HPP

#include "token.hpp"
#include <vector>

namespace lox {
    void run (std::string);
    std::vector<Token> scan(std::string);

}
#endif //LOX___SCANNER_HPP
