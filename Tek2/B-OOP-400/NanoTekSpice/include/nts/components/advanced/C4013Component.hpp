/*
** EPITECH PROJECT, 2024
** C4013Component.hpp
** File description:
** C4013Component.hpp
*/

#pragma once

#include "FlipFlopComponent.hpp"

namespace nts {
    class C4013Component : public IComponent {
    public:
        C4013Component() = default;
        virtual ~C4013Component() override = default;

        virtual void tick() override;
        virtual Pin& pin(std::size_t index) override;

    private:
        FlipFlopComponent _flipFlop1;
        FlipFlopComponent _flipFlop2;
    };
}
