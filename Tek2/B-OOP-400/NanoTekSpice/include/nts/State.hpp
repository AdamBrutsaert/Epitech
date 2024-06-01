/*
** EPITECH PROJECT, 2024
** State.hpp
** File description:
** State.hpp
*/

#pragma once

#include "Circuit.hpp"

namespace nts {
    struct State {
        std::unique_ptr<Circuit> circuit;
        bool running = true;
        std::vector<std::pair<std::string, Tristate>> set = {};
    };

    void run(const std::string& filename);
}
