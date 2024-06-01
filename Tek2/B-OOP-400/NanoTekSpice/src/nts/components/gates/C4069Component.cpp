/*
** EPITECH PROJECT, 2024
** C4069Component.cpp
** File description:
** C4069Component.cpp
*/

#include "nts/components/gates/C4069Component.hpp"

namespace nts {
    void C4069Component::tick()
    {
        this->_not1.tick();
        this->_not2.tick();
        this->_not3.tick();
        this->_not4.tick();
        this->_not5.tick();
        this->_not6.tick();
    }

    Pin& C4069Component::pin(std::size_t pin)
    {
        if (pin == 1) return this->_not1.pin(1);
        if (pin == 2) return this->_not1.pin(2);

        if (pin == 3) return this->_not2.pin(1);
        if (pin == 4) return this->_not2.pin(2);

        if (pin == 5) return this->_not3.pin(1);
        if (pin == 6) return this->_not3.pin(2);

        if (pin == 9) return this->_not4.pin(1);
        if (pin == 8) return this->_not4.pin(2);

        if (pin == 11) return this->_not5.pin(1);
        if (pin == 10) return this->_not5.pin(2);

        if (pin == 13) return this->_not6.pin(1);
        if (pin == 12) return this->_not6.pin(2);

        throw IComponent::InvalidPin();
    }
}
