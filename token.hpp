//
// Created by sutirtha8623 on 4/25/21.
//

#ifndef LOX___TOKEN_HPP
#define LOX___TOKEN_HPP

#include <string>

namespace lox {

    enum TokenType {
        LEFT_PAREN, RIGHT_PAREN, LEFT_BRACE, RIGHT_BRACE,
        COMMA, DOT, MINUS, PLUS, SEMICOLON, SLASH, STAR,

        BANG, BANG_EQUAL,
        EQUAL, EQUAL_EQUAL,
        GREATER, GREATER_EQUAL,
        LESS, LESS_EQUAL,

        IDENTIFIER, STRING, NUMBER,

        AND, CLASS, ELSE, FALSE, FUN, FOR, IF, NIL, OR,
        PRINT, RETURN, SUPER, THIS, TRUE, VAR, WHILE,

        END
    };

    class Token {
        TokenType type;
        std::string lexeme;
        int line;

    public:
        Token (TokenType t, std::string s, int l) : type(t), lexeme(s), line(l){}

        std::string to_string();
    };

}
#endif //LOX___TOKEN_HPP
