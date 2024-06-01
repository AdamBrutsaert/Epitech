/*
** EPITECH PROJECT, 2024
** FlipFlopComponent.cpp
** File description:
** FlipFlopComponent.cpp
*/

#include "nts/components/advanced/FlipFlopComponent.hpp"

namespace nts {
    FlipFlopComponent::FlipFlopComponent()
        : _clock(Pin::Type::Input)
    {
        // Nand1
        this->_nand1.pin(1).link(this->_not1.pin(2));
        this->_nand1.pin(2).link(this->_nand4.pin(4));
        this->_nand1.pin(3).link(this->_nand2.pin(4));

        // Nand2
        this->_nand2.pin(1).link(this->_nand1.pin(4));
        this->_nand2.pin(2).link(this->_clock);
        this->_nand2.pin(3).link(this->_not2.pin(2));

        // Nand3
        this->_nand3.pin(1).link(this->_nand2.pin(4));
        this->_nand3.pin(2).link(this->_clock);
        this->_nand3.pin(3).link(this->_nand4.pin(4));

        // Nand4
        this->_nand4.pin(1).link(this->_nand3.pin(4));
        this->_nand4.pin(3).link(this->_not2.pin(2));

        // Nand5
        this->_nand5.pin(1).link(this->_not1.pin(2));
        this->_nand5.pin(2).link(this->_nand2.pin(4));
        this->_nand5.pin(3).link(this->_nand6.pin(4));

        // Nand6
        this->_nand6.pin(1).link(this->_nand5.pin(4));
        this->_nand6.pin(2).link(this->_nand3.pin(4));
        this->_nand6.pin(3).link(this->_not2.pin(2));
    }

    void FlipFlopComponent::tick()
    {
    }

    Pin& FlipFlopComponent::pin(std::size_t pin)
    {
        if (pin == 1) return this->_nand4.pin(2);
        if (pin == 2) return this->_clock;
        if (pin == 3) return this->_not1.pin(1);
        if (pin == 4) return this->_not2.pin(1);
        if (pin == 5) return this->_nand5.pin(4);
        if (pin == 6) return this->_nand6.pin(4);
        throw IComponent::InvalidPin();
    }
}
