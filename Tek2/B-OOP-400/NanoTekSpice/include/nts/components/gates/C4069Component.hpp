/*
** EPITECH PROJECT, 2024
** C4069Component.hpp
** File description:
** C4069Component.hpp
*/

#pragma once

#include "nts/components/elementary/NotComponent.hpp"

namespace nts {
    class C4069Component : public IComponent {
    public:
        C4069Component() = default;
        virtual ~C4069Component() override = default;

        virtual void tick() override;
        virtual Pin& pin(std::size_t pin) override;

    private:
        NotComponent _not1;
        NotComponent _not2;
        NotComponent _not3;
        NotComponent _not4;
        NotComponent _not5;
        NotComponent _not6;
    };
}
