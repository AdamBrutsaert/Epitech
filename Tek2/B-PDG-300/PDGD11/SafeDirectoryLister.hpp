/*
** EPITECH PROJECT, 2024
** SafeSafeDirectoryLister.hpp
** File description:
** SafeSafeDirectoryLister.hpp
*/

#pragma once

#include "IDirectoryLister.hpp"

#include <dirent.h>

class SafeDirectoryLister : public IDirectoryLister {
public:
    SafeDirectoryLister();
    SafeDirectoryLister(const std::string &path, bool hidden);
    SafeDirectoryLister(const SafeDirectoryLister &lister) = delete;
    SafeDirectoryLister(SafeDirectoryLister &&lister) = delete;
    SafeDirectoryLister &operator=(const SafeDirectoryLister &lister) = delete;
    SafeDirectoryLister &operator=(SafeDirectoryLister &&lister) = delete;
    virtual ~SafeDirectoryLister() override;

    virtual bool open(const std::string &path, bool hidden) override;
    virtual std::string get() override;

private:
    DIR *_dir;
    bool _hidden;
};
