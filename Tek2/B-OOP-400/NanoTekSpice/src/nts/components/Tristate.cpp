/*
** EPITECH PROJECT, 2024
** Tristate.cpp
** File description:
** Tristate.cpp
*/

#include "nts/components/Tristate.hpp"

namespace nts {
    std::ostream& operator<<(std::ostream& os, Tristate state)
    {
        if (state == Tristate::Undefined) return os << "U";
        if (state == Tristate::True) return os << "1";
        return os << "0";
    }

    Tristate operator&&(Tristate a, Tristate b)
    {
        if (a == Tristate::True && b == Tristate::True) return Tristate::True;
        if (a == Tristate::False || b == Tristate::False) return Tristate::False;
        return Tristate::Undefined;
    }

    Tristate operator||(Tristate a, Tristate b)
    {
        if (a == Tristate::True || b == Tristate::True) return Tristate::True;
        if (a == Tristate::False && b == Tristate::False) return Tristate::False;
        return Tristate::Undefined;
    }

    Tristate operator^(Tristate a, Tristate b)
    {
        if (a == Tristate::Undefined || b == Tristate::Undefined) return Tristate::Undefined;
        if (a == b) return Tristate::False;
        return Tristate::True;
    }

    Tristate operator!(Tristate a)
    {
        if (a == Tristate::Undefined) return Tristate::Undefined;
        if (a == Tristate::True) return Tristate::False;
        return Tristate::True;
    }
}
