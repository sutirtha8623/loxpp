//
// Created by sutirtha8623 on 11/16/21.
//

#include "error.hpp"
#include <iostream>

namespace lox {

    void Error::setErrorState (bool b) {
        this->hadError = b;
    }

    void Error::report () {
        std::cout << "[line " << this->line << "] Error" << this->where << ": " << this->message << "\n";
        setErrorState(true);
    }
}
