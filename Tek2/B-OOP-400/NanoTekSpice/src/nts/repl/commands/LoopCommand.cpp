/*
** EPITECH PROJECT, 2024
** LoopCommand.cpp
** File description:
** LoopCommand.cpp
*/

#include "nts/repl/commands/LoopCommand.hpp"
#include "nts/repl/commands/SimulateCommand.hpp"
#include "nts/repl/commands/DisplayCommand.hpp"

#include <csignal>
#include <atomic>
#include <thread>

namespace nts::repl {
    static volatile std::atomic<bool> Looping = false;

    static void on_sigint([[maybe_unused]] int nb)
    {
        Looping = false;
    }

    void LoopCommand::execute(State& state)
    {
        Looping = true;

        // Setup sigaction
        struct sigaction action;
        action.sa_flags = 0;
        action.sa_handler = on_sigint;
        sigemptyset(&action.sa_mask);
        sigaction(SIGINT, &action, nullptr);

        while (Looping) {
            SimulateCommand{}.execute(state);
            DisplayCommand{}.execute(state);
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }

        // Clear sigaction
        action.sa_handler = SIG_DFL;
        sigaction(SIGINT, &action, nullptr);
    }
}
