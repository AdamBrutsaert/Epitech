/*
** EPITECH PROJECT, 2024
** C4008Component.cpp
** File description:
** C4008Component.cpp
*/

#include "nts/components/advanced/C4008Component.hpp"

namespace nts {

    C4008Component::C4008Component()
    {
        this->_adder2.pin(3).link(this->_adder1.pin(5));
        this->_adder3.pin(3).link(this->_adder2.pin(5));
        this->_adder4.pin(3).link(this->_adder3.pin(5));
    }

    void C4008Component::tick()
    {
        this->_adder1.tick();
        this->_adder2.tick();
        this->_adder3.tick();
        this->_adder4.tick();
    }

    Pin& C4008Component::pin(std::size_t pin)
    {
        if (pin == 1) return this->_adder4.pin(1);
        if (pin == 2) return this->_adder3.pin(2);
        if (pin == 3) return this->_adder3.pin(1);
        if (pin == 4) return this->_adder2.pin(2);
        if (pin == 5) return this->_adder2.pin(1);
        if (pin == 6) return this->_adder1.pin(2);
        if (pin == 7) return this->_adder1.pin(1);
        if (pin == 9) return this->_adder1.pin(3);
        if (pin == 10) return this->_adder1.pin(4);
        if (pin == 11) return this->_adder2.pin(4);
        if (pin == 12) return this->_adder3.pin(4);
        if (pin == 13) return this->_adder4.pin(4);
        if (pin == 14) return this->_adder4.pin(5);
        if (pin == 15) return this->_adder4.pin(2);
        throw IComponent::InvalidPin();
    }
}
