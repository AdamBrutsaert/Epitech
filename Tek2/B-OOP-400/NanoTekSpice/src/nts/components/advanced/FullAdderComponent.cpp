/*
** EPITECH PROJECT, 2024
** FullAdderComponent.cpp
** File description:
** FullAdderComponent.cpp
*/

#include "nts/components/advanced/FullAdderComponent.hpp"

namespace nts {
    FullAdderComponent::FullAdderComponent()
        : _operand_a(Pin::Type::Input),
          _operand_b(Pin::Type::Input),
          _carry_in(Pin::Type::Input)
    {
        _xor1.pin(1).link(_operand_a);
        _xor1.pin(2).link(_operand_b);

        _xor2.pin(1).link(_xor1.pin(3));
        _xor2.pin(2).link(_carry_in);

        _and1.pin(1).link(_carry_in);
        _and1.pin(2).link(_xor1.pin(3));

        _and2.pin(1).link(_operand_b);
        _and2.pin(2).link(_operand_a);

        _or1.pin(1).link(_and1.pin(3));
        _or1.pin(2).link(_and2.pin(3));
    }

    void FullAdderComponent::tick()
    {
        _xor1.tick();
        _xor2.tick();
        _and1.tick();
        _and2.tick();
        _or1.tick();
    }

    Pin& FullAdderComponent::pin(std::size_t pin)
    {
        if (pin == 1) return this->_operand_a;
        if (pin == 2) return this->_operand_b;
        if (pin == 3) return this->_carry_in;
        if (pin == 4) return this->_xor2.pin(3);
        if (pin == 5) return this->_or1.pin(3);
        throw IComponent::InvalidPin();
    }
}
