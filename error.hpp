//
// Created by sutirtha8623 on 11/16/21.
//

#ifndef LOXPP_ERROR_HPP
#define LOXPP_ERROR_HPP

#include <string>

namespace lox {
    class Error {
    private:
        int line;
        std::string where;
        std::string message;
        bool hadError;
    public:
        Error (int l, std::string w, std::string& m) : line(l), where(w), message(m) {}
        Error (int l, std::string m) : line(l), where(""), message(m) {}

        void setErrorState (bool b);

        void report ();
    };
}


#endif //LOXPP_ERROR_HPP
