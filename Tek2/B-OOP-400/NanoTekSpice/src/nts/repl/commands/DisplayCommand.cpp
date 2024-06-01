/*
** EPITECH PROJECT, 2024
** DisplayCommand.cpp
** File description:
** DisplayCommand.cpp
*/

#include "nts/repl/commands/DisplayCommand.hpp"

namespace nts::repl {
    void DisplayCommand::execute(State& state)
    {
        state.circuit->display();
    }
}
