/*
** EPITECH PROJECT, 2024
** C4094Component.hpp
** File description:
** C4094Component.hpp
*/

#pragma once

#include "nts/components/IComponent.hpp"

namespace nts {
    class C4094Component : public IComponent {
    public:
        C4094Component();
        virtual ~C4094Component() override = default;

        virtual void tick() override;
        virtual Pin& pin(std::size_t pin) override;

    private:
        void updateFallingEdge();
        void updateRisingEdge();

    private:
        Pin _clock;
        Pin _enable;
        Pin _strobe;
        Pin _data;

        std::vector<Pin> _outputs;
        Pin _serial;
        Pin _serialPrime;
    };
}
