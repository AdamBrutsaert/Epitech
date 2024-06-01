/*
** EPITECH PROJECT, 2024
** FlipFlopComponent.hpp
** File description:
** FlipFlopComponent.hpp
*/

#pragma once

#include "nts/components/elementary/C3NandComponent.hpp"
#include "nts/components/elementary/NotComponent.hpp"

namespace nts {
    class FlipFlopComponent : public IComponent {
    public:
        FlipFlopComponent();
        ~FlipFlopComponent() = default;

        virtual void tick() override;
        virtual Pin& pin(std::size_t pin) override;

    private:
        Pin _clock;

        NotComponent _not1;
        NotComponent _not2;

        C3NandComponent _nand1;
        C3NandComponent _nand2;
        C3NandComponent _nand3;
        C3NandComponent _nand4;
        C3NandComponent _nand5;
        C3NandComponent _nand6;
    };
}
