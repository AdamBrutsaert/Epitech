/*
** EPITECH PROJECT, 2024
** C4094Component.cpp
** File description:
** C4094Component.cpp
*/

#include "nts/components/advanced/C4094Component.hpp"

namespace nts {
    C4094Component::C4094Component()
        : _clock(Pin::Type::Input), _enable(Pin::Type::Input),
          _strobe(Pin::Type::Input), _data(Pin::Type::Input),
          _serial(Pin::Type::Output), _serialPrime(Pin::Type::Output)
    {
        for (std::size_t i = 0; i < 8; i++)
            _outputs.emplace_back(Pin::Type::Output);

        _clock.bind([&]() {
            if (_clock.state() == Tristate::True) {
                updateRisingEdge();
            } else if (_clock.state() == Tristate::False) {
                updateFallingEdge();
            }
        });
    }

    void C4094Component::updateFallingEdge()
    {
        if (_enable.state() == Tristate::False) {
            // Set Qs' to Q7
            _serialPrime.set(_outputs[6].state());

            // Set Qi to Undefined
            for (auto &output : _outputs)
                output.set(Tristate::Undefined);

        } else if (_enable.state() == Tristate::True
            && _strobe.state() == Tristate::True
            && _data.state() == Tristate::True
        ) {
            // Set Qs' to Q7
            _serialPrime.set(_outputs[6].state());
        }
    }

    void C4094Component::updateRisingEdge()
    {
        if (_enable.state() == Tristate::False) {
            // Set Qs to Q7
            _serial.set(_outputs[6].state());

            // Set Qi to Undefined
            for (auto &output : _outputs)
                output.set(Tristate::Undefined);

            return;
        }

        if (_enable.state() == Tristate::True
            && _strobe.state() == Tristate::False
        ) {
            // Set Qs to Q7
            _serial.set(_outputs[6].state());

            return;
        }

        if (_enable.state() == Tristate::True
            && _strobe.state() == Tristate::True) {

            // Set Qs to Q7
            _serial.set(_outputs[6].state());

            // Shift right
            for (std::size_t i = 7; i > 0; i--)
                _outputs[i].set(_outputs[i - 1].state());

            // Set Q0 to D
            _outputs[0].set(_data.state());

            return;
        }
    }

    void C4094Component::tick()
    {
    }

    Pin &C4094Component::pin(std::size_t pin)
    {
        if (pin == 1) return _strobe;
        if (pin == 2) return _data;
        if (pin == 3) return _clock;
        if (pin == 4) return _outputs[0];
        if (pin == 5) return _outputs[1];
        if (pin == 6) return _outputs[2];
        if (pin == 7) return _outputs[3];
        if (pin == 9) return _serial;
        if (pin == 10) return _serialPrime;
        if (pin == 11) return _outputs[7];
        if (pin == 12) return _outputs[6];
        if (pin == 13) return _outputs[5];
        if (pin == 14) return _outputs[4];
        if (pin == 15) return _enable;
        throw IComponent::InvalidPin();
    }
}
