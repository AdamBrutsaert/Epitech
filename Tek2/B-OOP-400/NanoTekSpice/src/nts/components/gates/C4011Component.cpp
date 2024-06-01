/*
** EPITECH PROJECT, 2024
** C4011Component.cpp
** File description:
** C4011Component.cpp
*/

#include "nts/components/gates/C4011Component.hpp"

namespace nts {
    void C4011Component::tick()
    {
        this->_nand1.tick();
        this->_nand2.tick();
        this->_nand3.tick();
        this->_nand4.tick();
    }

    Pin& C4011Component::pin(std::size_t pin)
    {
        if (pin == 1) return this->_nand1.pin(1);
        if (pin == 2) return this->_nand1.pin(2);
        if (pin == 3) return this->_nand1.pin(3);

        if (pin == 4) return this->_nand2.pin(3);
        if (pin == 5) return this->_nand2.pin(1);
        if (pin == 6) return this->_nand2.pin(2);

        if (pin == 8) return this->_nand3.pin(1);
        if (pin == 9) return this->_nand3.pin(2);
        if (pin == 10) return this->_nand3.pin(3);

        if (pin == 11) return this->_nand4.pin(3);
        if (pin == 12) return this->_nand4.pin(1);
        if (pin == 13) return this->_nand4.pin(2);

        throw IComponent::InvalidPin();
    }
}
