/*
** EPITECH PROJECT, 2024
** Token.hpp
** File description:
** Token.hpp
*/

#pragma once

#include <string>

namespace nts::conf {
    class Token {
    public:
        enum class Type {
            DOT_CHIPSETS = 0,
            DOT_LINKS,
            COLON,
            NUMBER,
            STRING,
            NEWLINE,
            END,
            UNKNOWN,
        };

    public:
        Token(Type type, std::string&& value, std::size_t line, std::size_t column);
        Token(const Token&) = default;
        Token(Token&&) = default;
        Token& operator=(const Token&) = default;
        Token& operator=(Token&&) = default;
        ~Token() = default;

        inline Type type() const { return this->_type; }
        inline const std::string& value() const { return this->_value; }
        inline std::size_t line() const { return this->_line; }
        inline std::size_t column() const { return this->_column; }

    public:
        static const char* TypeToString(Type type);

    private:
        Type _type;
        std::string _value;
        std::size_t _line;
        std::size_t _column;
    };
}
