/*
** EPITECH PROJECT, 2024
** XorComponent.cpp
** File description:
** XorComponent.cpp
*/

#include "nts/components/elementary/XorComponent.hpp"

namespace nts {
    XorComponent::XorComponent()
        : _input1(Pin::Type::Input), _input2(Pin::Type::Input),
          _output(Pin::Type::Output)
    {
        this->_input1.bind([&]() {
            this->_output.set(this->_input1.state() ^ this->_input2.state());
        });

        this->_input2.bind([&]() {
            this->_output.set(this->_input1.state() ^ this->_input2.state());
        });
    }

    void XorComponent::tick()
    {
    }

    Pin& XorComponent::pin(std::size_t pin)
    {
        if (pin == 1) return _input1;
        if (pin == 2) return _input2;
        if (pin == 3) return _output;
        throw IComponent::InvalidPin();
    }
}
