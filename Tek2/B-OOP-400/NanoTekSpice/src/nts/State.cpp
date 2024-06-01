/*
** EPITECH PROJECT, 2024
** State.cpp
** File description:
** State.cpp
*/

#include "nts/State.hpp"
#include "nts/configuration/Parsing.hpp"
#include "nts/repl/Parsing.hpp"

#include <iostream>

namespace nts {
    static bool prompt(State& state, repl::Lexer& lexer)
    {
        if (!state.running)
            return false;
        std::cout << "> " << std::flush;
        return lexer.read();
    }

    static void execute(State& state, repl::Lexer& lexer)
    {
        auto command = repl::parse(state, lexer);

        if (command != nullptr) {
            command->execute(state);
        } else {
            std::cerr << "Invalid command" << std::endl;
        }
    }

    void run(const std::string& filename)
    {
        State state{conf::parse(filename)};
        repl::Lexer lexer{std::make_unique<repl::Reader>()};

        while (prompt(state, lexer))
            execute(state, lexer);
    }
};
