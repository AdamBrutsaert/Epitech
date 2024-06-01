/*
** EPITECH PROJECT, 2024
** NandComponent.cpp
** File description:
** NandComponent.cpp
*/

#include "nts/components/elementary/NandComponent.hpp"

namespace nts {
    NandComponent::NandComponent()
    {
        this->_not.pin(1).link(this->_and.pin(3));
    }

    void NandComponent::tick()
    {
    }

    Pin& NandComponent::pin(std::size_t pin)
    {
        if (pin == 1) return this->_and.pin(1);
        if (pin == 2) return this->_and.pin(2);
        if (pin == 3) return this->_not.pin(2);
        throw IComponent::InvalidPin();
    }
}
