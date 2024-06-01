/*
** EPITECH PROJECT, 2024
** EmptyCommand.hpp
** File description:
** EmptyCommand.hpp
*/

#include "ICommand.hpp"

namespace nts::repl {
    class EmptyCommand : public ICommand {
      public:
        void execute(State& state) override;
    };
}
