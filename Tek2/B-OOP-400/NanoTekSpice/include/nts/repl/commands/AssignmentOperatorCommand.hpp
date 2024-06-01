/*
** EPITECH PROJECT, 2024
** AssignmentOperatorCommand.hpp
** File description:
** AssignmentOperatorCommand.hpp
*/

#pragma once

#include "ICommand.hpp"

namespace nts::repl {
    class AssignmentOperatorCommand : public ICommand {
    public:
        AssignmentOperatorCommand(std::string name, Tristate value);
        virtual void execute(State& state) override;
    private:
        std::string _name;
        Tristate _value;
    };
}
