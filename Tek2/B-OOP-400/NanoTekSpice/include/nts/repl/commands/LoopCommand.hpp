/*
** EPITECH PROJECT, 2024
** LoopCommand.hpp
** File description:
** LoopCommand.hpp
*/

#pragma once

#include "ICommand.hpp"

namespace nts::repl {
    class LoopCommand : public ICommand {
    public:
        virtual void execute(State& state) override;
    };
}
