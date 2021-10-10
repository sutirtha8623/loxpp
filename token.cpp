//
// Created by sutirtha8623 on 4/25/21.
//

#include "token.hpp"
#include <map>
#include <string>

namespace lox {

    std::string Token::to_string() {
        const static std::map<TokenType, std::string> enum_strings {

            {TokenType::LEFT_PAREN, "LEFT_PAREN"},
            {TokenType::RIGHT_PAREN, "RIGHT_PAREN"},
            {TokenType::LEFT_BRACE, "LEFT_BRACE"},
            {TokenType::RIGHT_BRACE, "RIGHT_BRACE"},
            {TokenType::COMMA, "COMMA"},
            {TokenType::DOT, "DOT"},
            {TokenType::MINUS, "MINUS"},
            {TokenType::PLUS, "PLUS"},
            {TokenType::SEMICOLON, "SEMICOLON"},
            {TokenType::SLASH, "SLASH"},
            {TokenType::STAR, "STAR"},

            {TokenType::BANG, "BANG"},
            {TokenType::BANG_EQUAL, "BANG_EQUAL"},
            {TokenType::EQUAL, "EQUAL"},
            {TokenType::EQUAL_EQUAL, "EQUAL_EQUAL"},
            {TokenType::GREATER, "GREATER"},
            {TokenType::GREATER_EQUAL, "GREATER_EQUAL"},
            {TokenType::LESS, "LESS"},
            {TokenType::LESS_EQUAL, "LESS_EQUAL"},

            {TokenType::IDENTIFIER, "IDENTIFIER"},
            {TokenType::STRING, "STRING"},
            {TokenType::NUMBER, "NUMBER"},

            {TokenType::AND, "AND"},
            {TokenType::CLASS, "CLASS"},
            {TokenType::ELSE, "ELSE"},
            {TokenType::FALSE, "FALSE"},
            {TokenType::FUN, "FUN"},
            {TokenType::FOR, "FOR"},
            {TokenType::IF, "IF"},
            {TokenType::NIL, "NIL"},
            {TokenType::OR, "OR"},
            {TokenType::PRINT, "PRINT"},
            {TokenType::RETURN, "RETURN"},
            {TokenType::SUPER, "THIS"},
            {TokenType::THIS, "THIS"},
            {TokenType::TRUE, "TRUE"},
            {TokenType::VAR, "VAR"},
            {TokenType::WHILE, "WHILE"},

            {TokenType::END, "END"},
        };

        auto it = enum_strings.find(type);
        std::string result = it->second + " " + lexeme;
        return result;
    }
}