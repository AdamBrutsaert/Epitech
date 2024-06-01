/*
** EPITECH PROJECT, 2024
** SetCommand.hpp
** File description:
** SetCommand.hpp
*/

#pragma once

#include "ICommand.hpp"

namespace nts::repl {
    class SetCommand : public ICommand {
    public:
        virtual void execute(State& state) override;
    };
}
