/*
** EPITECH PROJECT, 2024
** DirectoryLister.hpp
** File description:
** DirectoryLister.hpp
*/

#pragma once

#include "IDirectoryLister.hpp"

#include <dirent.h>

class DirectoryLister : public IDirectoryLister {
public:
    DirectoryLister();
    DirectoryLister(const std::string &path, bool hidden);
    DirectoryLister(const DirectoryLister &lister) = delete;
    DirectoryLister(DirectoryLister &&lister) = delete;
    DirectoryLister &operator=(const DirectoryLister &lister) = delete;
    DirectoryLister &operator=(DirectoryLister &&lister) = delete;
    virtual ~DirectoryLister() override;

    virtual bool open(const std::string &path, bool hidden) override;
    virtual std::string get() override;

private:
    DIR *_dir;
    bool _hidden;
};
