/*
** EPITECH PROJECT, 2024
** C4017Component.hpp
** File description:
** C4017Component.hpp
*/

#pragma once

#include "nts/components/IComponent.hpp"

namespace nts {
    class C4017Component : public IComponent {
    public:
        C4017Component();
        virtual ~C4017Component() override = default;

        virtual void tick() override;
        virtual Pin& pin(std::size_t pin) override;

    private:
        void update();

    private:
        Pin _inhibit;
        Pin _clock;
        Pin _reset;
        std::vector<Pin> _outputs;
        Pin _carry;
    };
}
