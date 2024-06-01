/*
** EPITECH PROJECT, 2024
** C4013Component.cpp
** File description:
** C4013Component.cpp
*/

#include "nts/components/advanced/C4013Component.hpp"

namespace nts {
    void C4013Component::tick()
    {
    }

    Pin &C4013Component::pin(std::size_t index)
    {
        if (index == 1) return _flipFlop1.pin(5);
        if (index == 2) return _flipFlop1.pin(6);
        if (index == 3) return _flipFlop1.pin(2);
        if (index == 4) return _flipFlop1.pin(4);
        if (index == 5) return _flipFlop1.pin(1);
        if (index == 6) return _flipFlop1.pin(3);

        if (index == 8) return _flipFlop2.pin(3);
        if (index == 9) return _flipFlop2.pin(1);
        if (index == 10) return _flipFlop2.pin(4);
        if (index == 11) return _flipFlop2.pin(2);
        if (index == 12) return _flipFlop2.pin(6);
        if (index == 13) return _flipFlop2.pin(5);

        throw IComponent::InvalidPin();
    }
}
