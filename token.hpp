//
// Created by sutirtha8623 on 4/25/21.
//

#ifndef LOXPP_TOKEN_HPP
#define LOXPP_TOKEN_HPP

#include <string>
#include <memory>

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
        std::shared_ptr<void> literal;
        int line;

    public:
        Token (TokenType t, std::string s, std::shared_ptr<void> lit ,int l) : type(t), lexeme(s), literal(lit) ,line(l){}
        ~Token () {}

        std::string toString();
    };

}
#endif //LOXPP_TOKEN_HPP
