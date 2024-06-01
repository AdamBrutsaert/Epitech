/*
** EPITECH PROJECT, 2024
** C4017Component.cpp
** File description:
** C4017Component.cpp
*/

#include "nts/components/advanced/C4017Component.hpp"

namespace nts {
    C4017Component::C4017Component()
        : _inhibit(Pin::Type::Input), _clock(Pin::Type::Input),
          _reset(Pin::Type::Input), _carry(Pin::Type::Output)
    {
        for (std::size_t i = 0; i < 10; i++)
            _outputs.emplace_back(Pin::Type::Output);

        _clock.bind(std::bind(&C4017Component::update, this));
        _inhibit.bind(std::bind(&C4017Component::update, this));

        _reset.bind([&]() {
            if (_reset.state() != Tristate::True)
                return;
            for (std::size_t i = 0; i < 10; i++)
                _outputs[i].set(i == 0 ? Tristate::True : Tristate::False);
            _carry.set(Tristate::True);
        });
    }

    void C4017Component::update()
    {
        if (_clock.state() != Tristate::True)
            return;
        if (_inhibit.state() != Tristate::False)
            return;

        std::size_t index;
        bool found = false;

        for (std::size_t i = 0; i < 10; i++) {
            if (_outputs[i].state() == Tristate::True) {
                index = i;
                found = true;
                break;
            }
        }

        if (!found)
            return;

        _outputs[index].set(Tristate::False);
        index = (index + 1) % 10;
        _outputs[index].set(Tristate::True);
        _carry.set(index < 5 ? Tristate::True : Tristate::False);
    }

    void C4017Component::tick()
    {
    }

    Pin& C4017Component::pin(std::size_t pin)
    {
        if (pin == 1) return _outputs[5];
        if (pin == 2) return _outputs[1];
        if (pin == 3) return _outputs[0];
        if (pin == 4) return _outputs[2];
        if (pin == 5) return _outputs[6];
        if (pin == 6) return _outputs[7];
        if (pin == 7) return _outputs[3];
        if (pin == 9) return _outputs[8];
        if (pin == 10) return _outputs[4];
        if (pin == 11) return _outputs[9];
        if (pin == 12) return _carry;
        if (pin == 13) return _inhibit;
        if (pin == 14) return _clock;
        if (pin == 15) return _reset;
        throw IComponent::InvalidPin();
    }
}
