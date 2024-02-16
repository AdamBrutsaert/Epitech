/*
** EPITECH PROJECT, 2024
** Command.hpp
** File description:
** Command.hpp
*/

#pragma once

#include <exception>
#include <functional>
#include <map>
#include <string>

class Command {
public:
    class Error : public std::exception {
    public:
        Error(const std::string& message);
        virtual const char *what() const noexcept override;
    private:
        std::string _message;
    };

public:
    Command() = default;
    ~Command() = default;

    void registerCommand(const std::string& name, const std::function<void()>& function);
    void executeCommand(const std::string& name);

private:
    std::map<std::string, std::function<void()>> _map;
};
