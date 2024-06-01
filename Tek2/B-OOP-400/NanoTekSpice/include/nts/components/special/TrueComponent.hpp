/*
** EPITECH PROJECT, 2024
** TrueComponent.hpp
** File description:
** TrueComponent.hpp
*/

#pragma once

#include "nts/components/IComponent.hpp"

namespace nts {
    class TrueComponent : public IComponent {
    public:
        TrueComponent();
        virtual ~TrueComponent() override = default;

        virtual void tick() override;
        virtual Pin& pin(std::size_t pin) override;

    private:
        Pin _output;
    };
}
