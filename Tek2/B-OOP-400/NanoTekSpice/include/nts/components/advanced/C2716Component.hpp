/*
** EPITECH PROJECT, 2024
** C2716Component.hpp
** File description:
** C2716Component.hpp
*/

#pragma once

#include "nts/components/IComponent.hpp"

#include <stdint.h>

namespace nts {
    class C2716Component : public IComponent {
    public:
        C2716Component();
        virtual ~C2716Component() override = default;

        virtual void tick() override;
        virtual Pin& pin(std::size_t pin) override;

    private:
        void update();

    private:
        std::vector<Pin> _address;
        std::vector<Pin> _data;
        Pin _disableChipset;
        Pin _disableOutput;

        std::vector<uint8_t> _memory;
    };
}
