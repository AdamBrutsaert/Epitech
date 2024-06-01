/*
** EPITECH PROJECT, 2024
** LoggerComponent.cpp
** File description:
** LoggerComponent.cpp
*/

#include "nts/components/advanced/LoggerComponent.hpp"

#include <stdint.h>

namespace nts {
    LoggerComponent::LoggerComponent()
        : _file("./log.bin", std::ios_base::app),
          _clock(Pin::Type::Input),
          _inhibit(Pin::Type::Input)
    {
        for (std::size_t i = 0; i < 8; i++)
            _inputs.emplace_back(Pin::Type::Input);
        _clock.bind([&]() {
            if (!_file)
                return;
            if (_clock.state() != Tristate::True)
                return;
            if (_inhibit.state() != Tristate::False)
                return;
            for (auto &pin : _inputs) {
                if (pin.state() == Tristate::Undefined)
                    return;
            }
            uint8_t character = 0;
            character += _inputs[0].state() == Tristate::True ? 1 : 0;
            character += _inputs[1].state() == Tristate::True ? 2 : 0;
            character += _inputs[2].state() == Tristate::True ? 4 : 0;
            character += _inputs[3].state() == Tristate::True ? 8 : 0;
            character += _inputs[4].state() == Tristate::True ? 16 : 0;
            character += _inputs[5].state() == Tristate::True ? 32 : 0;
            character += _inputs[6].state() == Tristate::True ? 64 : 0;
            character += _inputs[7].state() == Tristate::True ? 128 : 0;
            _file.write(reinterpret_cast<char *>(&character), sizeof(character));
        });
    }

    void LoggerComponent::tick()
    {
    }

    Pin &LoggerComponent::pin(std::size_t pin)
    {
        if (pin == 1) return _inputs[0];
        if (pin == 2) return _inputs[1];
        if (pin == 3) return _inputs[2];
        if (pin == 4) return _inputs[3];
        if (pin == 5) return _inputs[4];
        if (pin == 6) return _inputs[5];
        if (pin == 7) return _inputs[6];
        if (pin == 8) return _inputs[7];
        if (pin == 9) return _clock;
        if (pin == 10) return _inhibit;
        throw IComponent::InvalidPin();
    }
}
