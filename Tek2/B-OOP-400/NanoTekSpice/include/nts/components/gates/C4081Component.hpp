/*
** EPITECH PROJECT, 2024
** C4081Component.hpp
** File description:
** C4081Component.hpp
*/

#pragma once

#include "nts/components/elementary/AndComponent.hpp"

namespace nts {
    class C4081Component : public IComponent {
    public:
        C4081Component() = default;
        virtual ~C4081Component() override = default;

        virtual void tick() override;
        virtual Pin& pin(std::size_t pin) override;

    private:
        AndComponent _and1;
        AndComponent _and2;
        AndComponent _and3;
        AndComponent _and4;
    };
}
