/*
** EPITECH PROJECT, 2024
** IDirectoryLister.cpp
** File description:
** IDirectoryLister.cpp
*/

#include "IDirectoryLister.hpp"

#include <cstring>

IDirectoryLister::OpenFailureException::OpenFailureException(int code)
    : _code(code)
{
}

const char *IDirectoryLister::OpenFailureException::what() const noexcept
{
    return strerror(this->_code);
}

const char *IDirectoryLister::NoMoreFileException::what() const noexcept
{
    return "End of stream";
}
