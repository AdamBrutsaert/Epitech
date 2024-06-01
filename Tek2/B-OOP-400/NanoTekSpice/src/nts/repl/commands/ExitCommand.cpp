/*
** EPITECH PROJECT, 2024
** ExitCommand.cpp
** File description:
** ExitCommand.cpp
*/

#include "nts/repl/commands/ExitCommand.hpp"

namespace nts::repl {
    void ExitCommand::execute(State& state)
    {
        state.running = false;
    }
}
