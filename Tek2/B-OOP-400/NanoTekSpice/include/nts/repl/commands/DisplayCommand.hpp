/*
** EPITECH PROJECT, 2024
** DisplayCommand.hpp
** File description:
** DisplayCommand.hpp
*/

#pragma once

#include "ICommand.hpp"

namespace nts::repl {
    class DisplayCommand : public ICommand {
    public:
        virtual void execute(State& state) override;
    };
}
