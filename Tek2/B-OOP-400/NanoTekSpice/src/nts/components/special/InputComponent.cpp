/*
** EPITECH PROJECT, 2024
** InputComponent.cpp
** File description:
** InputComponent.cpp
*/

#include "nts/components/special/InputComponent.hpp"

namespace nts {
    InputComponent::InputComponent()
        : _output(Pin::Type::Output)
    {
    }

    void InputComponent::tick()
    {
    }

    Pin& InputComponent::pin(std::size_t pin)
    {
        if (pin == 1) return _output;
        throw IComponent::InvalidPin();
    }
}
