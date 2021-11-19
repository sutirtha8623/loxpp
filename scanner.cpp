//
// Created by sutirtha8623 on 11/16/21.
//

#include "scanner.hpp"
#include "token.hpp"
#include "error.hpp"
#include <vector>
#include <memory>

namespace lox {

    std::map<std::string, TokenType> Scanner::keywords {
            {"and", AND},
            {"class", CLASS},
            {"else", ELSE},
            {"false", FALSE},
            {"fun", FUN},
            {"if", IF},
            {"nil", NIL},
            {"or", OR},
            {"print", PRINT},
            {"return", RETURN},
            {"super", SUPER},
            {"this", THIS},
            {"true", TRUE},
            {"var", VAR},
            {"while", WHILE}
    };

    std::vector<Token>& Scanner::scanTokens() {
        while (!isAtEnd()) {
            this->start = this->current;
            scanToken();
        }

        this->tokens.push_back(Token(END, "", nullptr, this->line));
        return this->tokens;
    }

    void Scanner::scanToken () {
        char c = advance();
        switch (c) {
            case '(': addToken(LEFT_PAREN); break;
            case ')': addToken(RIGHT_PAREN); break;
            case '{': addToken(LEFT_BRACE); break;
            case '}': addToken(RIGHT_BRACE); break;
            case ',': addToken(COMMA); break;
            case '.': addToken(DOT); break;
            case '-': addToken(MINUS); break;
            case '+': addToken(PLUS); break;
            case ';': addToken(SEMICOLON); break;
            case '*': addToken(STAR); break;

            case '!':
                addToken(match('=') ? BANG_EQUAL : BANG);
                break;
            case '=':
                addToken(match('=') ? EQUAL_EQUAL : EQUAL);
                break;
            case '<':
                addToken(match('=') ? LESS_EQUAL : LESS);
                break;
            case '>':
                addToken(match('=') ? GREATER_EQUAL : GREATER);
                break;

            case '/':
                if (match('/')) {
                    while (peek() != '\n' && !isAtEnd()) advance();
                }
                else {
                    addToken(SLASH);
                }
                break;

            case ' ':
            case '\r':
            case '\t':
                break;

            case '\n':
                this->line++;
                break;

            case '"': string(); break;

            default:
                if (isDigit(c)) {
                    number();
                }
                else if (isAlpha(c)) {
                    identifier();
                }
                else {
                    throw Error(this->line, "Unexpected character.");
                }
        }
    }

    void Scanner::identifier () {
        while (isAlphaNumeric(peek())) advance();

        std::string val = this->source.substr(this->start, this->current - this->start + 1);

        auto it = keywords.find(val);
        if (it == keywords.end()) addToken(IDENTIFIER);
        else {
            addToken(it->second);
        }
    }

    void Scanner::number () {
        while (isDigit(peek())) advance();

        if (peek() == '.' && isDigit(peekNext())) {
            advance();
            while (isDigit(peek())) advance();
        }

        std::string val = this->source.substr(this->start, this->current - this->start + 1);
        addToken(NUMBER, static_cast<std::shared_ptr<void>>(&val));
    }

    void Scanner::string () {
        while (peek() != '"' && !isAtEnd()) {
            if (peek() == '\n') this->line++;
            advance();
        }
        if (isAtEnd()) {
            throw Error(this->line, "Unterminated string");
        }

        advance();

        std::string val = this->source.substr(this->start + 1, this->current - this->start);
        addToken(STRING, static_cast<std::shared_ptr<void>>(&val));
    }

    bool Scanner::match (char expected) {
        if (isAtEnd()) return false;
        if (this->source[current] != expected) return false;

        current++;
        return true;
    }

    char Scanner::peek() {
        if (isAtEnd()) return '\0';
        return this->source[current];
    }

    char Scanner::peekNext () {
        if (this->current + 1 >= this->source.length()) return '\0';
        return this->source[this->current + 1];
    }

    bool Scanner::isAlpha (char c) {
        return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c == '_');
    }

    bool Scanner::isAlphaNumeric (char c) {
        return isAlpha(c) || isDigit(c);
    }

    bool Scanner::isDigit (char c) {
        return (c >= '0' && c <= '9');
    }

    bool Scanner::isAtEnd () {
        return this->current >= this->source.length();
    }

    char Scanner::advance () {
        return this->source[this->current++];
    }

    void Scanner::addToken(TokenType t) {
        addToken(t, nullptr);
    }
    void Scanner::addToken (TokenType t, std::shared_ptr<void> literal) {
        std::string text = this->source.substr(this->start, this->current - this->start + 1);
        this->tokens.push_back(Token(t, text, literal, this->line));
    }
};