/*
** EPITECH PROJECT, 2024
** NorComponent.cpp
** File description:
** NorComponent.cpp
*/

#include "nts/components/elementary/NorComponent.hpp"

namespace nts {
    NorComponent::NorComponent()
        : _or(), _not()
    {
        this->_not.pin(1).link(this->_or.pin(3));
    }

    void NorComponent::tick()
    {
    }

    Pin& NorComponent::pin(std::size_t pin)
    {
        if (pin == 1) return this->_or.pin(1);
        if (pin == 2) return this->_or.pin(2);
        if (pin == 3) return this->_not.pin(2);
        throw IComponent::InvalidPin();
    }
}
