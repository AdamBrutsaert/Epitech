/*
** EPITECH PROJECT, 2024
** C4801Component.hpp
** File description:
** C4801Component.hpp
*/

#pragma once

#include "nts/components/IComponent.hpp"

#include <stdint.h>

namespace nts {
    class C4801Component : public IComponent {
    public:
        C4801Component();
        ~C4801Component() = default;

        virtual void tick() override;
        virtual Pin& pin(std::size_t pin) override;

    private:
        void update();

    private:
        std::vector<Pin> _address;
        std::vector<Pin> _data;

        Pin _disableChipset;
        Pin _disableOutput;
        Pin _disableWrite;

        std::vector<uint8_t> _memory;
    };
}
