/*
** EPITECH PROJECT, 2024
** C4008Component.hpp
** File description:
** C4008Component.hpp
*/

#pragma once

#include "FullAdderComponent.hpp"

namespace nts {
    class C4008Component : public IComponent {
    public:
        C4008Component();
        virtual ~C4008Component() override = default;

        virtual void tick() override;
        virtual Pin& pin(std::size_t pin) override;

    private:
        FullAdderComponent _adder1;
        FullAdderComponent _adder2;
        FullAdderComponent _adder3;
        FullAdderComponent _adder4;
    };
}
