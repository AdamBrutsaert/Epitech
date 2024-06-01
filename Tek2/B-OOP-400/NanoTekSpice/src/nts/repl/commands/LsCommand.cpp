/*
** EPITECH PROJECT, 2024
** LsCommand.cpp
** File description:
** LsCommand.cpp
*/

#include "nts/repl/commands/LsCommand.hpp"

#include <iostream>

namespace nts::repl {
    void LsCommand::execute(State& state)
    {
        std::cout << "component(s):" << std::endl;
        for (const auto& [name, _] : state.circuit->components())
            std::cout << "  " << name << std::endl;
    }
}
