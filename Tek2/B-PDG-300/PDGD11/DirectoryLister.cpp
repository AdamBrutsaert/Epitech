/*
** EPITECH PROJECT, 2024
** DirectoryLister.cpp
** File description:
** DirectoryLister.cpp
*/

#include "DirectoryLister.hpp"

DirectoryLister::DirectoryLister()
    : _dir(nullptr), _hidden(false)
{
}

DirectoryLister::DirectoryLister(const std::string &path, bool hidden)
    : _dir(nullptr), _hidden(false)
{
    this->open(path, hidden);
}

DirectoryLister::~DirectoryLister()
{
    if (this->_dir != nullptr)
        closedir(this->_dir);
}

bool DirectoryLister::open(const std::string &path, bool hidden)
{
    if (this->_dir != nullptr)
        closedir(this->_dir);

    this->_hidden = hidden;
    this->_dir = opendir(path.c_str());

    if (this->_dir == nullptr) {
        perror(path.c_str());
        return false;
    }

    return true;
}

std::string DirectoryLister::get()
{
    if (this->_dir == nullptr)
        return "";

    struct dirent *entry = nullptr;

    while ((entry = readdir(this->_dir)) != nullptr) {
        if (this->_hidden || entry->d_name[0] != '.')
            return entry->d_name;
    }

    return "";
}
