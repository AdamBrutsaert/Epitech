/*
** EPITECH PROJECT, 2024
** Command.cpp
** File description:
** Command.cpp
*/

#include "Command.hpp"

Command::Error::Error(const std::string& message)
    : _message(message)
{
}

const char *Command::Error::what() const noexcept
{
    return this->_message.c_str();
}

void Command::registerCommand(const std::string& name, const std::function<void()>& function)
{
    if (this->_map[name])
        throw Command::Error("Already registered command");

    this->_map[name] = function;
}

void Command::executeCommand(const std::string& name)
{
    if (!this->_map[name])
        throw Command::Error("Unknow command");

    this->_map[name]();
}
