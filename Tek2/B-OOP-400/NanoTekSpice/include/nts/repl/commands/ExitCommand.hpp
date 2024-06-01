/*
** EPITECH PROJECT, 2024
** ExitCommand.hpp
** File description:
** ExitCommand.hpp
*/

#pragma once

#include "ICommand.hpp"

namespace nts::repl {
    class ExitCommand : public ICommand {
    public:
        virtual void execute(State& state) override;
    };
}
