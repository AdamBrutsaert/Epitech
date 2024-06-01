/*
** EPITECH PROJECT, 2024
** ClockComponent.hpp
** File description:
** ClockComponent.hpp
*/

#pragma once

#include "nts/components/IComponent.hpp"

namespace nts {
    class ClockComponent : public IComponent {
    public:
        ClockComponent();
        virtual ~ClockComponent() override = default;

        virtual void tick() override;
        virtual Pin& pin(std::size_t pin) override;

    private:
        Pin _output;
    };
}
