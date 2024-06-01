/*
** EPITECH PROJECT, 2024
** Reader.cpp
** File description:
** Reader.cpp
*/

#include "nts/configuration/Reader.hpp"

#include <fstream>
#include <sstream>

namespace nts::conf {
    Reader::LoadFailure::LoadFailure(const std::string& filename)
    {
        this->_what = "Failed to load file \"" + filename + "\"";
    }
}

namespace nts::conf {
    Reader::Reader(const std::string& filename)
        : _buffer(), _cursor(0), _line(1), _column(1)
    {
        std::ifstream file(filename);

        if (!file)
            throw Reader::LoadFailure(filename);

        std::stringstream buffer;
        buffer << file.rdbuf();
        this->_buffer = buffer.str();
    }

    char Reader::next()
    {
        if (this->_cursor >= this->_buffer.size())
            return '\0';

        if (this->_buffer[this->_cursor] == '\n') {
            this->_line++;
            this->_column = 1;
        } else {
            this->_column++;
        }

        return this->_buffer[this->_cursor++];
    }

    char Reader::peek() const
    {
        if (this->_cursor >= this->_buffer.size())
            return '\0';

        return this->_buffer[this->_cursor];
    }

    static bool isWordChar(char c)
    {
        return (c >= 'a' && c <= 'z')
            || (c >= 'A' && c <= 'Z')
            || (c >= '0' && c <= '9')
            || c == '_' || c == '.';
    }

    static bool isWhitespaceChar(char c)
    {
        return c == ' ' || c == '\t' || c == '\r';
    }

    static bool isUnexpectedChar(char c)
    {
        return !isWordChar(c) && !isWhitespaceChar(c) && c != '\n' && c != '\0';
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

    void Reader::skipWhitespaceUntilNewline()
    {
        for (char c = this->peek(); isWhitespaceChar(c); c = this->peek())
            this->next();
    }

    void Reader::skipUntilNewline()
    {
        for (char c = this->peek(); c != '\n' && c != '\0'; c = this->peek())
            this->next();
    }
}
