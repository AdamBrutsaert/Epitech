/*
** EPITECH PROJECT, 2024
** SimulateCommand.hpp
** File description:
** SimulateCommand.hpp
*/

#pragma once

#include "ICommand.hpp"

namespace nts::repl {
    class SimulateCommand : public ICommand {
    public:
        virtual void execute(State& state) override;
    };
}
