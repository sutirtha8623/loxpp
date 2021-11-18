//
// Created by sutirtha8623 on 11/16/21.
//

#include "scanner.hpp"
#include "token.hpp"
#include "error.hpp"
#include <vector>

namespace lox {
    std::vector<Token>& Scanner::scanTokens() {
        while (!isAtEnd()) {
            this->start = this->current;
            scanToken();
        }

        this->tokens.push_back(Token(END, "", this->line));
        return this->tokens;
    }

    void Scanner::scanToken () {
        char c = advance();
        switch (c) {
            case '(' : addToken(LEFT_PAREN); break;
            case ')': addToken(RIGHT_PAREN); break;
            case '{' : addToken(LEFT_BRACE); break;
            case '}' : addToken(RIGHT_BRACE); break;
            case ',' : addToken(COMMA); break;
            case '.' : addToken(DOT); break;
            case '-' : addToken(MINUS); break;
            case '+' : addToken(PLUS); break;
            case ';' : addToken(SEMICOLON); break;
            case '*' : addToken(STAR); break;

            default:
                throw Error(this->line, "Unexpected character.");
        }
    }

    bool Scanner::isAtEnd() {
        return current >= this->source.length();
    }

    char Scanner::advance () {
        return this->source[this->current++];
    }

    void Scanner::addToken (TokenType t) {
        std::string text = this->source.substr(this->start, this->current - this->start + 1);
        this->tokens.push_back(Token(t, text, this->line));
    }
};