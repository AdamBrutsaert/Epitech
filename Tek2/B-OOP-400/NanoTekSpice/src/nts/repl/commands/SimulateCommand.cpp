/*
** EPITECH PROJECT, 2024
** SimulateCommand.cpp
** File description:
** SimulateCommand.cpp
*/

#include "nts/repl/commands/SimulateCommand.hpp"

namespace nts::repl {
    void SimulateCommand::execute(State& state)
    {
        state.circuit->simulate();

        // Set new values
        for (auto& [name, value] : state.set)
            state.circuit->getInput(name)->pin(1).set(value);
        state.set.clear();
    }
}
