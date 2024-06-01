/*
** EPITECH PROJECT, 2024
** C2716Component.cpp
** File description:
** C2716Component.cpp
*/

#include "nts/components/advanced/C2716Component.hpp"

#include <fstream>
#include <string.h>

namespace nts {
    C2716Component::C2716Component()
        : _disableChipset(Pin::Type::Input), _disableOutput(Pin::Type::Input)
    {
        _memory.resize(2048, 0);

        // Load the ROM from the file
        std::ifstream file("./rom.bin");
        if (!!file) {
            file.read(reinterpret_cast<char*>(_memory.data()), _memory.size());
            file.close();
        }

        for (std::size_t i = 0; i < 11; i++)
            _address.emplace_back(Pin::Type::Input);
        for (std::size_t i = 0; i < 8; i++)
            _data.emplace_back(Pin::Type::Output);

        for (std::size_t i = 0; i < 11; i++)
            _address[i].bind(std::bind(&C2716Component::update, this));
        _disableChipset.bind(std::bind(&C2716Component::update, this));
        _disableOutput.bind(std::bind(&C2716Component::update, this));
        this->update();
    }

    void C2716Component::update()
    {
        // If the chipset is disabled, we don't do anything
        if (_disableChipset.state() != nts::Tristate::False)
            return;

        // If the output is disabled we set all the output pins to undefined
        if (_disableOutput.state() != nts::Tristate::False) {
            for (std::size_t i = 0; i < 8; i++)
                _data[i].set(Tristate::Undefined);
            return;
        }

        // Calculate the address
        std::size_t address = 0;
        bool address_undefined = false;

        for (std::size_t i = 0; i < 11; i++) {
            auto state = _address[i].state();

            if (state == Tristate::Undefined) {
                address_undefined = true;
                break;
            }

            address |= (state == Tristate::True) << i;
        }

        // If the address is undefined, we set all the output pins to undefined
        if (address_undefined) {
            for (std::size_t i = 0; i < 8; i++)
                _data[i].set(Tristate::Undefined);
            return;
        }

        // Set the output pins to the value of the memory
        for (std::size_t i = 0; i < 8; i++) {
            _data[i].set(
                (_memory[address] >> i) & 1
                    ? Tristate::True
                    : Tristate::False
            );
        }
    }

    void C2716Component::tick()
    {
    }

    Pin& C2716Component::pin(std::size_t pin)
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
        if (pin == 19) return _address[10];
        if (pin == 20) return _disableOutput;
        if (pin == 22) return _address[9];
        if (pin == 23) return _address[8];
        throw IComponent::InvalidPin();
    }
}
