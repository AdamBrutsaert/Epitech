/*
** EPITECH PROJECT, 2024
** C4040Component.hpp
** File description:
** C4040Component.hpp
*/

#pragma once

#include "nts/components/IComponent.hpp"

namespace nts {
    class C4040Component : public IComponent {
    public:
        C4040Component();
        virtual ~C4040Component() override = default;

        virtual void tick() override;
        virtual Pin& pin(std::size_t pin) override;

    private:
        void update();

    private:
        Pin _clock;
        Pin _reset;
        std::vector<Pin> _outputs;
    };
}
