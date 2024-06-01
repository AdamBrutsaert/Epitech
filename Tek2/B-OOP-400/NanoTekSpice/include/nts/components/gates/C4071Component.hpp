/*
** EPITECH PROJECT, 2024
** C4071Component.hpp
** File description:
** C4071Component.hpp
*/

#pragma once

#include "nts/components/elementary/OrComponent.hpp"

namespace nts {
    class C4071Component : public IComponent {
    public:
        C4071Component() = default;
        virtual ~C4071Component() override = default;

        virtual void tick() override;
        virtual Pin& pin(std::size_t pin) override;

    private:
        OrComponent _or1;
        OrComponent _or2;
        OrComponent _or3;
        OrComponent _or4;
    };
}
