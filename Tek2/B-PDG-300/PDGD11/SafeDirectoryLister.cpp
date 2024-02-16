/*
** EPITECH PROJECT, 2024
** SafeDirectoryLister.cpp
** File description:
** SafeDirectoryLister.cpp
*/

#include "SafeDirectoryLister.hpp"

#include <errno.h>

SafeDirectoryLister::SafeDirectoryLister()
    : _dir(nullptr), _hidden(false)
{
}

SafeDirectoryLister::SafeDirectoryLister(const std::string &path, bool hidden)
    : _dir(nullptr), _hidden(false)
{
    this->open(path, hidden);
}

SafeDirectoryLister::~SafeDirectoryLister()
{
    if (this->_dir != nullptr)
        closedir(this->_dir);
}

bool SafeDirectoryLister::open(const std::string &path, bool hidden)
{
    if (this->_dir != nullptr)
        closedir(this->_dir);

    this->_hidden = hidden;
    this->_dir = opendir(path.c_str());

    if (this->_dir == nullptr)
        throw OpenFailureException(errno);

    return true;
}

std::string SafeDirectoryLister::get()
{
    if (this->_dir == nullptr)
        throw NoMoreFileException();

    struct dirent *entry = nullptr;

    while ((entry = readdir(this->_dir)) != nullptr) {
        if (this->_hidden || entry->d_name[0] != '.')
            return entry->d_name;
    }

    throw NoMoreFileException();
}
