/*
** EPITECH PROJECT, 2024
** ClearCommand.hpp
** File description:
** ClearCommand.hpp
*/

#pragma once

#include "ICommand.hpp"

namespace nts::repl {
    class ClearCommand : public ICommand {
    public:
        virtual void execute(State& state) override;
    };
}
