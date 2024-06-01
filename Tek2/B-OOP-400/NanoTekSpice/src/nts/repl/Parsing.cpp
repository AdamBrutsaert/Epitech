/*
** EPITECH PROJECT, 2024
** Parsing.cpp
** File description:
** Parsing.cpp
*/

#include "nts/repl/Parsing.hpp"

#include "nts/repl/commands/EmptyCommand.hpp"
#include "nts/repl/commands/ExitCommand.hpp"
#include "nts/repl/commands/DisplayCommand.hpp"
#include "nts/repl/commands/SimulateCommand.hpp"
#include "nts/repl/commands/AssignmentOperatorCommand.hpp"
#include "nts/repl/commands/LoopCommand.hpp"
#include "nts/repl/commands/ClearCommand.hpp"
#include "nts/repl/commands/LsCommand.hpp"
#include "nts/repl/commands/SetCommand.hpp"

namespace nts::repl {
    std::unique_ptr<ICommand> parse(State& state, Lexer& lexer)
    {
        auto tokens = lexer.all();

        if (tokens.empty() || tokens[0].type() == Token::Type::END)
            return std::make_unique<EmptyCommand>();

        if (tokens.size() == 2) {
            if (tokens[0].type() != Token::Type::STRING)  return nullptr;
            if (tokens[1].type() != Token::Type::END)  return nullptr;

            if (tokens[0].value() == "exit") return std::make_unique<ExitCommand>();
            else if (tokens[0].value() == "display") return std::make_unique<DisplayCommand>();
            else if (tokens[0].value() == "simulate") return std::make_unique<SimulateCommand>();
            else if (tokens[0].value() == "loop") return std::make_unique<LoopCommand>();
            else if (tokens[0].value() == "clear") return std::make_unique<ClearCommand>();
            else if (tokens[0].value() == "ls") return std::make_unique<LsCommand>();
            else if (tokens[0].value() == "set") return std::make_unique<SetCommand>();

            return nullptr;
        }

        if (tokens.size() == 4) {
            if (tokens[0].type() != Token::Type::STRING)  return nullptr;
            if (tokens[1].type() != Token::Type::EQUAL)  return nullptr;
            if (tokens[2].type() != Token::Type::STRING)  return nullptr;
            if (tokens[3].type() != Token::Type::END)  return nullptr;

            try {
                auto component = state.circuit->getInput(tokens[0].value());

                if (tokens[2].value() == "0") return std::make_unique<AssignmentOperatorCommand>(tokens[0].value(), Tristate::False);
                else if (tokens[2].value() == "1") return std::make_unique<AssignmentOperatorCommand>(tokens[0].value(), Tristate::True);
                else if (tokens[2].value() == "U") return std::make_unique<AssignmentOperatorCommand>(tokens[0].value(), Tristate::Undefined);
                else std::cerr << "Invalid state" << std::endl;
            } catch (const Circuit::ComponentNotFound& e) {
                std::cerr << "Component \"" << tokens[0].value() << "\" not found" << std::endl;
            } catch (const Circuit::ComponentIsNotAnInput& e) {
                std::cerr << "Component \"" << tokens[0].value() << "\" is not an input" << std::endl;
            }
        }

        return nullptr;
    }
}
