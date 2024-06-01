/*
** EPITECH PROJECT, 2024
** OrComponent.cpp
** File description:
** OrComponent.cpp
*/

#include "nts/components/elementary/OrComponent.hpp"

namespace nts {
    OrComponent::OrComponent()
        : _input1(Pin::Type::Input), _input2(Pin::Type::Input),
          _output(Pin::Type::Output)
    {
        this->_input1.bind([&]() {
            this->_output.set(this->_input1.state() || this->_input2.state());
        });

        this->_input2.bind([&]() {
            this->_output.set(this->_input1.state() || this->_input2.state());
        });
    }

    void OrComponent::tick()
    {
    }

    Pin& OrComponent::pin(std::size_t pin)
    {
        if (pin == 1) return _input1;
        if (pin == 2) return _input2;
        if (pin == 3) return _output;
        throw IComponent::InvalidPin();
    }
}
