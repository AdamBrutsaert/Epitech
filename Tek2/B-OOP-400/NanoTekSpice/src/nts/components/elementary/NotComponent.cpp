/*
** EPITECH PROJECT, 2024
** NotComponent.cpp
** File description:
** NotComponent.cpp
*/

#include "nts/components/elementary/NotComponent.hpp"

namespace nts {
    NotComponent::NotComponent()
        : _input(Pin::Type::Input), _output(Pin::Type::Output)
    {
        this->_input.bind([&]() {
            this->_output.set(!this->_input.state());
        });
    }

    void NotComponent::tick()
    {
    }

    Pin& NotComponent::pin(std::size_t pin)
    {
        if (pin == 1) return _input;
        if (pin == 2) return _output;
        throw IComponent::InvalidPin();
    }
}
