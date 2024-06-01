/*
** EPITECH PROJECT, 2024
** C4514Component.cpp
** File description:
** C4514Component.cpp
*/

#include "nts/components/advanced/C4514Component.hpp"

namespace nts {
    C4514Component::C4514Component()
        : _inhibit(Pin::Type::Input), _strobe(Pin::Type::Input)
    {
        for (int i = 0; i < 4; i++)
            _inputs.push_back(Pin::Type::Input);
        for (int i = 0; i < 16; i++)
            _outputs.push_back(Pin::Type::Output);

        _strobe.bind(std::bind(&C4514Component::update, this));
        _inhibit.bind(std::bind(&C4514Component::update, this));
        for (int i = 0; i < 4; i++)
            _inputs[i].bind(std::bind(&C4514Component::update, this));

        this->update();
    }

    void C4514Component::update()
    {
        if (_inhibit.state() == Tristate::True) {
            for (int i = 0; i < 16; i++)
                _outputs[i].set(Tristate::False);
            return;
        }

        if (_inhibit.state() == Tristate::Undefined) {
            for (int i = 0; i < 16; i++)
                _outputs[i].set(Tristate::Undefined);
            return;
        }

        if (_strobe.state() != Tristate::True)
            return;

        int index = 0;
        bool undefined = false;

        for (int i = 0; i < 4; i++) {
            if (_inputs[i].state() == Tristate::Undefined) {
                undefined = true;
                break;
            }
            if (_inputs[i].state() == Tristate::True)
                index += 1 << i;
        }

        if (undefined) {
            for (int i = 0; i < 16; i++)
                _outputs[i].set(Tristate::Undefined);
        } else {
            for (int i = 0; i < 16; i++)
                _outputs[i].set(index == i ? Tristate::True : Tristate::False);
        }
    }

    void C4514Component::tick()
    {
    }

    Pin &C4514Component::pin(std::size_t pin)
    {
        if (pin == 1) return _strobe;
        if (pin == 2) return _inputs[0];
        if (pin == 3) return _inputs[1];
        if (pin == 4) return _outputs[7];
        if (pin == 5) return _outputs[6];
        if (pin == 6) return _outputs[5];
        if (pin == 7) return _outputs[4];
        if (pin == 8) return _outputs[3];
        if (pin == 9) return _outputs[1];
        if (pin == 10) return _outputs[2];
        if (pin == 11) return _outputs[0];
        if (pin == 13) return _outputs[13];
        if (pin == 14) return _outputs[12];
        if (pin == 15) return _outputs[15];
        if (pin == 16) return _outputs[14];
        if (pin == 17) return _outputs[9];
        if (pin == 18) return _outputs[8];
        if (pin == 19) return _outputs[11];
        if (pin == 20) return _outputs[10];
        if (pin == 21) return _inputs[2];
        if (pin == 22) return _inputs[3];
        if (pin == 23) return _inhibit;
        throw IComponent::InvalidPin();
    }
}
