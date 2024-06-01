/*
** EPITECH PROJECT, 2024
** C4514Component.hpp
** File description:
** C4514Component.hpp
*/

#pragma once

#include "nts/components/IComponent.hpp"

namespace nts {
    class C4514Component : public IComponent {
    public:
        C4514Component();
        virtual ~C4514Component() override = default;

        virtual void tick() override;
        virtual Pin& pin(std::size_t pin) override;

    private:
        void update();

    private:
        Pin _inhibit;
        Pin _strobe;
        std::vector<Pin> _inputs;
        std::vector<Pin> _outputs;
    };
}
