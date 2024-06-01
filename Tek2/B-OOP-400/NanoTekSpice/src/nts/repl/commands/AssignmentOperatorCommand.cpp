/*
** EPITECH PROJECT, 2024
** AssignmentOperatorCommand.cpp
** File description:
** AssignmentOperatorCommand.cpp
*/

#include "nts/repl/commands/AssignmentOperatorCommand.hpp"

namespace nts::repl {
    AssignmentOperatorCommand::AssignmentOperatorCommand(std::string name, Tristate value)
        : _name{name}, _value{value}
    {
    }

    void AssignmentOperatorCommand::execute(State& state)
    {
        state.set.push_back({_name, _value});
    }
}
