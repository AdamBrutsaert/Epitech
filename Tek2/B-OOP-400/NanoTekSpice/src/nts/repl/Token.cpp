/*
** EPITECH PROJECT, 2024
** Token.cpp
** File description:
** Token.cpp
*/

#include "nts/repl/Token.hpp"

namespace nts::repl {
    Token::Token(Type type, std::string&& value)
        : _type(type), _value(std::move(value))
    {
    }

    const char* Token::TypeToString(Type type)
    {
        switch (type) {
        case Type::EQUAL:   return "EQUAL";
        case Type::STRING:  return "STRING";
        case Type::END:     return "END";
        default:            return "UNKNOWN";
        }
    }
}
