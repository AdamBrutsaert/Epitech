/*
** EPITECH PROJECT, 2024
** Shell.hpp
** File description:
** Shell.hpp
*/

#pragma once

#include <exception>
#include <iostream>
#include <sstream>

class Shell {
public:
    class Error : public std::exception {
    public:
        Error(std::string const& message);
        ~Error() = default;

        const char* what() const noexcept override;
    private:
        std::string _message;
    };

    class Warning : public std::exception {
    public:
        Warning(std::string const& message);
        ~Warning() = default;

        const char* what() const noexcept override;
    private:
        std::string _message;
    };

public:
    Shell(std::istream& stream);
    ~Shell() = default;

    void next();

    template<typename T>
    T extract()
    {
        T value;
        _line >> value;
        if (_line.fail())
            throw Shell::Warning("Invalid conversion");
        return value;
    }


private:
    std::stringstream _line;
    std::istream& _stream;
};
