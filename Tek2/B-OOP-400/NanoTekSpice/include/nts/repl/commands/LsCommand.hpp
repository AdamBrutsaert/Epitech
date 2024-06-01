/*
** EPITECH PROJECT, 2024
** LsCommand.hpp
** File description:
** LsCommand.hpp
*/

#include "ICommand.hpp"

namespace nts::repl {
    class LsCommand : public ICommand {
      public:
        void execute(State& state) override;
    };
}
