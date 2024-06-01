/*
** EPITECH PROJECT, 2024
** C4801Component.cpp
** File description:
** C4801Component.cpp
*/

#include "nts/components/advanced/C4801Component.hpp"

namespace nts {
    C4801Component::C4801Component()
        : _disableChipset(Pin::Type::Input),
          _disableOutput(Pin::Type::Input),
          _disableWrite(Pin::Type::Input)
    {
        _memory.resize(1024, 0);

        for (std::size_t i = 0; i < 10; i++)
            _address.emplace_back(Pin::Type::Input);
        for (std::size_t i = 0; i < 8; i++)
            _data.emplace_back(Pin::Type::Hybrid);

        _disableChipset.bind(std::bind(&C4801Component::update, this));
        _disableOutput.bind(std::bind(&C4801Component::update, this));
        _disableWrite.bind(std::bind(&C4801Component::update, this));

        for (auto &pin : _address)
            pin.bind(std::bind(&C4801Component::update, this));
        for (auto &pin : _data)
            pin.bind(std::bind(&C4801Component::update, this));
    }

    void C4801Component::update()
    {
        std::size_t address = 0;
        bool undefined_address = false;

        for (std::size_t i = 0; i < 10; i++) {
            if (_address[i].state() == Tristate::Undefined) {
                undefined_address = true;
                break;
            }
            address |= (_address[i].state() == Tristate::True) << i;
        }

        if (_disableChipset.state() == Tristate::True) {
            // Set all data to Undefined
            for (auto &pin : _data)
                pin.set(Tristate::Undefined);
            return;
        }

        if (_disableChipset.state() == Tristate::False
            && _disableWrite.state() == Tristate::False
        ) {
            if (undefined_address)
                return;

            std::size_t data = 0;

            for (std::size_t i = 0; i < 8; i++) {
                if (_data[i].state() == Tristate::Undefined)
                    return;
                data |= (_data[i].state() == Tristate::True) << i;
            }

            // write to memory
            _memory[address] = data;

            return;
        }

        if (_disableChipset.state() == Tristate::False
            && _disableOutput.state() == Tristate::False
            && _disableWrite.state() == Tristate::True
        ) {
            if (undefined_address)
                return;

            // read from memory
            for (std::size_t i = 0; i < 8; i++)
                _data[i].set((_memory[address] >> i) & 1 ? Tristate::True : Tristate::False);

            return;
        }

        if (_disableChipset.state() == Tristate::False
            && _disableOutput.state() == Tristate::True
            && _disableWrite.state() == Tristate::True) {
            // Set all data to Undefined
            for (auto &pin : _data)
                pin.set(Tristate::Undefined);
        }
    }

    void C4801Component::tick()
    {
    }

    Pin& C4801Component::pin(std::size_t pin)
    {
        if (pin == 1) return _address[7];
        if (pin == 2) return _address[6];
        if (pin == 3) return _address[5];
        if (pin == 4) return _address[4];
        if (pin == 5) return _address[3];
        if (pin == 6) return _address[2];
        if (pin == 7) return _address[1];
        if (pin == 8) return _address[0];
        if (pin == 9) return _data[0];
        if (pin == 10) return _data[1];
        if (pin == 11) return _data[2];
        if (pin == 13) return _data[3];
        if (pin == 14) return _data[4];
        if (pin == 15) return _data[5];
        if (pin == 16) return _data[6];
        if (pin == 17) return _data[7];
        if (pin == 18) return _disableChipset;
        if (pin == 20) return _disableOutput;
        if (pin == 21) return _disableWrite;
        if (pin == 22) return _address[9];
        if (pin == 23) return _address[8];
        throw IComponent::InvalidPin();
    }
}
