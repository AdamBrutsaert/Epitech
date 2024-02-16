/*
** EPITECH PROJECT, 2024
** Shell.cpp
** File description:
** Shell.cpp
*/

#include "Shell.hpp"

Shell::Error::Error(std::string const &message)
    : _message(message)
{
}

const char *Shell::Error::what() const noexcept
{
    return _message.c_str();
}

Shell::Warning::Warning(std::string const &message)
    : _message(message)
{
}

const char *Shell::Warning::what() const noexcept
{
    return _message.c_str();
}

Shell::Shell(std::istream &stream)
    : _line(), _stream(stream)
{
}

void Shell::next()
{
    std::string line;

    if (!std::getline(_stream, line)) {
        if (this->_stream.eof())
            throw Shell::Error("End of input");
        throw Shell::Error("Input failed");
    }

    _line.clear();
    _line.str(line);
}
