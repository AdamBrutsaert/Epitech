/*
** EPITECH PROJECT, 2024
** ClearCommand.cpp
** File description:
** ClearCommand.cpp
*/

#include "nts/repl/commands/ClearCommand.hpp"

#include <iostream>

namespace nts::repl {
    void ClearCommand::execute([[maybe_unused]] State& state)
    {
        std::cout << "\033[2J\033[H";
    }
}
