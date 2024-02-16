/*
** EPITECH PROJECT, 2024
** IDirectoryLister.hpp
** File description:
** IDirectoryLister.hpp
*/

#pragma once

#include <string>
#include <exception>

class IDirectoryLister {
public:

    class OpenFailureException : public std::exception {
    public:
        OpenFailureException(int code);

        virtual const char *what() const noexcept override;
    private:
        int _code;
    };

    class NoMoreFileException : public std::exception {
    public:
        virtual const char *what() const noexcept override;
    };

public:
    virtual ~IDirectoryLister() = default;

    virtual bool open(const std::string &path, bool hidden) = 0;
    virtual std::string get() = 0;
};
