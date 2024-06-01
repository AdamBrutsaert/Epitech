/*
** EPITECH PROJECT, 2024
** TrueComponent.cpp
** File description:
** TrueComponent.cpp
*/

#include "nts/components/special/TrueComponent.hpp"

namespace nts {
    TrueComponent::TrueComponent()
        : _output(Pin::Type::Output)
    {
        this->_output.set(Tristate::True);
    }

    void TrueComponent::tick()
    {
    }

    Pin& TrueComponent::pin(std::size_t pin)
    {
        if (pin == 1) return _output;
        throw IComponent::InvalidPin();
    }
}
