/*
** EPITECH PROJECT, 2024
** Token.cpp
** File description:
** Token.cpp
*/

#include "nts/configuration/Token.hpp"

namespace nts::conf {
    Token::Token(Type type, std::string&& value, std::size_t line, std::size_t column)
        : _type(type), _value(std::move(value)), _line(line), _column(column)
    {
    }

    const char* Token::TypeToString(Type type)
    {
        switch (type) {
            case Type::DOT_CHIPSETS: return "DOT_CHIPSETS";
            case Type::DOT_LINKS:    return "DOT_LINKS";
            case Type::COLON:        return "COLON";
            case Type::NUMBER:       return "NUMBER";
            case Type::STRING:       return "STRING";
            case Type::NEWLINE:      return "NEWLINE";
            case Type::END:          return "END";
            default:                 return "UNKNOWN";
        }
    }
}
