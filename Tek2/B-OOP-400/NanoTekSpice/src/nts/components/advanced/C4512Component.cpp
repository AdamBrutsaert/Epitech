/*
** EPITECH PROJECT, 2024
** C4512Component.cpp
** File description:
** C4512Component.cpp
*/

#include "nts/components/advanced/C4512Component.hpp"

namespace nts {
    C4512Component::C4512Component()
        : _inhibit(Pin::Type::Input), _disable(Pin::Type::Input),
          _output(Pin::Type::Output)
    {
        for (std::size_t i = 0; i < 8; i++)
            _inputs.push_back(Pin::Type::Input);
        for (std::size_t i = 0; i < 3; i++)
            _address.push_back(Pin::Type::Input);

        for (std::size_t i = 0; i < 8; i++)
            _inputs[i].bind(std::bind(&C4512Component::update, this));
        for (std::size_t i = 0; i < 3; i++)
            _address[i].bind(std::bind(&C4512Component::update, this));
        _inhibit.bind(std::bind(&C4512Component::update, this));
        _disable.bind(std::bind(&C4512Component::update, this));
    }

    void C4512Component::update()
    {
        bool address_undefined = false;
        std::size_t address = 0;

        for (std::size_t i = 0; i < 3; i++) {
            auto state = _address[i].state();

            if (state == Tristate::Undefined) {
                address_undefined = true;
                break;
            }

            address |= (state == Tristate::True) << i;
        }

        // If disable is set to True or Undefined, the output is Undefined
        if (_disable.state() != Tristate::False) {
            _output.set(Tristate::Undefined);
            return;
        }

        // If inhibit is set to True, or the value at the
        // address is False, the output is False
        if (_inhibit.state() == Tristate::True
            || (!address_undefined && _inputs[address].state() == Tristate::False)
        ) {
            _output.set(Tristate::False);
            return;
        }

        // If the address is undefined, the output is undefined
        if (address_undefined) {
            _output.set(Tristate::Undefined);
            return;
        }

        // Otherwise, the output is the value at the address
        _output.set(_inputs[address].state());
    }

    void C4512Component::tick()
    {
    }

    Pin &C4512Component::pin(std::size_t pin)
    {
        if (pin == 1) return _inputs[0];
        if (pin == 2) return _inputs[1];
        if (pin == 3) return _inputs[2];
        if (pin == 4) return _inputs[3];
        if (pin == 5) return _inputs[4];
        if (pin == 6) return _inputs[5];
        if (pin == 7) return _inputs[6];
        if (pin == 9) return _inputs[7];
        if (pin == 10) return _inhibit;
        if (pin == 11) return _address[0];
        if (pin == 12) return _address[1];
        if (pin == 13) return _address[2];
        if (pin == 14) return _output;
        if (pin == 15) return _disable;
        throw IComponent::InvalidPin();
    }
}
