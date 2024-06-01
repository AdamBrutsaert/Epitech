/*
** EPITECH PROJECT, 2024
** C4001Component.hpp
** File description:
** C4001Component.hpp
*/

#pragma once

#include "nts/components/elementary/NorComponent.hpp"

namespace nts {
    class C4001Component : public IComponent {
    public:
        C4001Component() = default;
        virtual ~C4001Component() override = default;

        virtual void tick() override;
        virtual Pin& pin(std::size_t pin) override;

    private:
        NorComponent _nor1;
        NorComponent _nor2;
        NorComponent _nor3;
        NorComponent _nor4;
    };
}
