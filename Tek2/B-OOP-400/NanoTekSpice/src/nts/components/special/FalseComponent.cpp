/*
** EPITECH PROJECT, 2024
** FalseComponent.cpp
** File description:
** FalseComponent.cpp
*/

#include "nts/components/special/FalseComponent.hpp"

namespace nts {
    FalseComponent::FalseComponent()
        : _output(Pin::Type::Output)
    {
        this->_output.set(Tristate::False);
    }

    void FalseComponent::tick()
    {
    }

    Pin& FalseComponent::pin(std::size_t pin)
    {
        if (pin == 1) return _output;
        throw IComponent::InvalidPin();
    }
}
