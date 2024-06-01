/*
** EPITECH PROJECT, 2024
** Token.hpp
** File description:
** Token.hpp
*/

#include <string>

namespace nts::repl {
    class Token {
    public:
        enum class Type {
            EQUAL = 0,
            STRING,
            END,
            UNKNOWN,
        };

    public:
        Token(Type type, std::string&& value);
        Token(const Token&) = default;
        Token(Token&&) = default;
        Token& operator=(const Token&) = default;
        Token& operator=(Token&&) = default;
        ~Token() = default;

        inline Type type() const { return this->_type; }
        inline const std::string& value() const { return this->_value; }

    public:
        static const char* TypeToString(Type type);

    private:
        Type _type;
        std::string _value;
    };
}
