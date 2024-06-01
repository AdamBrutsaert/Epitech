/*
** EPITECH PROJECT, 2024
** SRLatchComponent.cpp
** File description:
** SRLatchComponent.cpp
*/

#include "nts/components/advanced/SRLatchComponent.hpp"

namespace nts {
    SRLatchComponent::SRLatchComponent()
    {
        this->_nor1.pin(2).link(this->_nor2.pin(3));
        this->_nor2.pin(1).link(this->_nor1.pin(3));
    }

    void SRLatchComponent::tick()
    {
    }

    Pin& SRLatchComponent::pin(std::size_t pin)
    {
        if (pin == 1) return _nor2.pin(2);
        if (pin == 2) return _nor1.pin(1);
        if (pin == 3) return _nor1.pin(3);
        if (pin == 4) return _nor2.pin(3);
        throw IComponent::InvalidPin();
    }
}
