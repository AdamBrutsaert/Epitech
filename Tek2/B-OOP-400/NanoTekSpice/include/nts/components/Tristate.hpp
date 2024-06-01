/*
** EPITECH PROJECT, 2024
** Tristate.hpp
** File description:
** Tristate.hpp
*/

#pragma once

#include <iostream>

namespace nts {
    enum class Tristate {
        Undefined = (-true),
        True = true,
        False = false
    };

    std::ostream& operator<<(std::ostream& os, Tristate state);
    Tristate operator&&(Tristate a, Tristate b);
    Tristate operator||(Tristate a, Tristate b);
    Tristate operator^(Tristate a, Tristate b);
    Tristate operator!(Tristate a);
}
