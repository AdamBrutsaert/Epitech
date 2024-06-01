/*
** EPITECH PROJECT, 2024
** C4030Component.hpp
** File description:
** C4030Component.hpp
*/

#pragma once

#include "nts/components/elementary/XorComponent.hpp"

namespace nts {
    class C4030Component : public IComponent {
    public:
        C4030Component() = default;
        virtual ~C4030Component() override = default;

        virtual void tick() override;
        virtual Pin& pin(std::size_t pin) override;

    private:
        XorComponent _xor1;
        XorComponent _xor2;
        XorComponent _xor3;
        XorComponent _xor4;
    };
}
