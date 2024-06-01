/*
** EPITECH PROJECT, 2024
** FullAdderComponent.hpp
** File description:
** FullAdderComponent.hpp
*/

#pragma once

#include "nts/components/elementary/XorComponent.hpp"
#include "nts/components/elementary/AndComponent.hpp"
#include "nts/components/elementary/OrComponent.hpp"

namespace nts {
    class FullAdderComponent : public IComponent {
    public:
        FullAdderComponent();
        virtual ~FullAdderComponent() override = default;

        virtual void tick() override;
        virtual Pin& pin(std::size_t pin) override;

    private:
        Pin _operand_a;
        Pin _operand_b;
        Pin _carry_in;

        XorComponent _xor1;
        XorComponent _xor2;
        AndComponent _and1;
        AndComponent _and2;
        OrComponent _or1;
    };
}
