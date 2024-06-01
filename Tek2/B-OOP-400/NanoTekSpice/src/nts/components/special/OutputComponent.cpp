/*
** EPITECH PROJECT, 2024
** OutputComponent.cpp
** File description:
** OutputComponent.cpp
*/

#include "nts/components/special/OutputComponent.hpp"

namespace nts {
    OutputComponent::OutputComponent()
        : _input(Pin::Type::Input)
    {
    }

    void OutputComponent::tick()
    {
    }

    Pin& OutputComponent::pin(std::size_t pin)
    {
        if (pin == 1) return _input;
        throw IComponent::InvalidPin();
    }
}
