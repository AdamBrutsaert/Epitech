/*
** EPITECH PROJECT, 2024
** Command.hpp
** File description:
** Command.hpp
*/

#pragma once

#include "nts/State.hpp"

namespace nts::repl {
    class ICommand {
    public:
        virtual ~ICommand() = default;

        virtual void execute(State& state) = 0;
    };
}
