/*
** EPITECH PROJECT, 2024
** C4001Component.cpp
** File description:
** C4001Component.cpp
*/

#include "nts/components/gates/C4001Component.hpp"

namespace nts {
    void C4001Component::tick()
    {
        this->_nor1.tick();
        this->_nor2.tick();
        this->_nor3.tick();
        this->_nor4.tick();
    }

    Pin& C4001Component::pin(std::size_t pin)
    {
        if (pin == 1) return this->_nor1.pin(1);
        if (pin == 2) return this->_nor1.pin(2);
        if (pin == 3) return this->_nor1.pin(3);

        if (pin == 4) return this->_nor2.pin(3);
        if (pin == 5) return this->_nor2.pin(1);
        if (pin == 6) return this->_nor2.pin(2);

        if (pin == 8) return this->_nor3.pin(1);
        if (pin == 9) return this->_nor3.pin(2);
        if (pin == 10) return this->_nor3.pin(3);

        if (pin == 11) return this->_nor4.pin(3);
        if (pin == 12) return this->_nor4.pin(1);
        if (pin == 13) return this->_nor4.pin(2);

        throw IComponent::InvalidPin();
    }
}
