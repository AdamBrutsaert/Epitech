/*
** EPITECH PROJECT, 2024
** Reader.cpp
** File description:
** Reader.cpp
*/

#include "nts/repl/Reader.hpp"

#include <iostream>
#include <sstream>

namespace nts::repl {
    Reader::Reader()
        : _buffer(), _cursor(0)
    {
    }

    bool Reader::read()
    {
        if (!std::getline(std::cin, this->_buffer))
            return false;
        this->_cursor = 0;
        return true;
    }

    char Reader::next()
    {
        if (this->_cursor >= this->_buffer.size())
            return '\0';
        return this->_buffer[this->_cursor++];
    }

    char Reader::peek() const
    {
        if (this->_cursor >= this->_buffer.size())
            return '\0';
        return this->_buffer[this->_cursor];
    }

    static bool isWhitespaceChar(char c)
    {
        return c == ' ' || c == '\t' || c == '\r' || c == '\n';
    }

    static bool isWordChar(char c)
    {
        return (c >= 'a' && c <= 'z')
            || (c >= 'A' && c <= 'Z')
            || (c >= '0' && c <= '9')
            || c == '_' || c == '.';
    }

    static bool isUnexpectedChar(char c)
    {
        return !isWordChar(c) && !isWhitespaceChar(c) && c != '\0';
    }

    std::string Reader::nextWord()
    {
        std::stringstream word;

        while (isWordChar(this->peek()))
            word << this->next();

        return word.str();
    }

    std::string Reader::nextUnexpectedWord()
    {
        std::stringstream word;

        while (isUnexpectedChar(this->peek()))
            word << this->next();

        return word.str();
    }

    void Reader::skipWhitespace()
    {
        while (isWhitespaceChar(this->peek()))
            this->next();
    }
}
