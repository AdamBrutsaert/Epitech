/*
** EPITECH PROJECT, 2024
** C3NandComponent.cpp
** File description:
** C3NandComponent.cpp
*/

#include "nts/components/elementary/C3NandComponent.hpp"

namespace nts {
    C3NandComponent::C3NandComponent()
        : _input1(Pin::Type::Input), _input2(Pin::Type::Input),
          _input3(Pin::Type::Input), _output(Pin::Type::Output)
    {
        this->_input1.bind(std::bind(&C3NandComponent::update, this));
        this->_input2.bind(std::bind(&C3NandComponent::update, this));
        this->_input3.bind(std::bind(&C3NandComponent::update, this));
    }

    void C3NandComponent::update()
    {
        this->_output.set(
            !(
                this->_input1.state()
                && this->_input2.state()
                && this->_input3.state()
            )
        );
    }

    void C3NandComponent::tick()
    {
    }

    Pin& C3NandComponent::pin(std::size_t pin)
    {
        if (pin == 1) return this->_input1;
        if (pin == 2) return this->_input2;
        if (pin == 3) return this->_input3;
        if (pin == 4) return this->_output;
        throw IComponent::InvalidPin();
    }
}
