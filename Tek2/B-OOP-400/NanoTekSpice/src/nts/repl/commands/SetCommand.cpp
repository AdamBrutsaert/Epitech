/*
** EPITECH PROJECT, 2024
** SetCommand.cpp
** File description:
** SetCommand.cpp
*/

#include "nts/repl/commands/SetCommand.hpp"

#include <iostream>

namespace nts::repl {
    void SetCommand::execute([[maybe_unused]] State& state)
    {
        std::cout << "next state(s):" << std::endl;
        for (const auto& [name, state] : state.set)
            std::cout << "  " << name << " -> " << state << std::endl;
    }
}
