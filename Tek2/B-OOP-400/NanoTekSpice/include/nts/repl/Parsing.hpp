/*
** EPITECH PROJECT, 2024
** Parsing.hpp
** File description:
** Parsing.hpp
*/

#pragma once

#include "Lexer.hpp"
#include "commands/ICommand.hpp"
#include "nts/State.hpp"

namespace nts::repl {
    std::unique_ptr<ICommand> parse(State& state, Lexer& lexer);
}
