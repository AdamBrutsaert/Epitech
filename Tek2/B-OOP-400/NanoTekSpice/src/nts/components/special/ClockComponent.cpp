/*
** EPITECH PROJECT, 2024
** ClockComponent.cpp
** File description:
** ClockComponent.cpp
*/

#include "nts/components/special/ClockComponent.hpp"

namespace nts {
    ClockComponent::ClockComponent()
        : _output(Pin::Type::Output)
    {
    }

    void ClockComponent::tick()
    {
        this->_output.set(!this->_output.state());
    }

    Pin& ClockComponent::pin(std::size_t pin)
    {
        if (pin == 1) return _output;
        throw IComponent::InvalidPin();
    }
}
