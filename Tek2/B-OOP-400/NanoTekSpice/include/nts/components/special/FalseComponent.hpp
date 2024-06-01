/*
** EPITECH PROJECT, 2024
** FalseComponent.hpp
** File description:
** FalseComponent.hpp
*/

#pragma once

#include "nts/components/IComponent.hpp"

namespace nts {
    class FalseComponent : public IComponent {
    public:
        FalseComponent();
        virtual ~FalseComponent() override = default;

        virtual void tick() override;
        virtual Pin& pin(std::size_t pin) override;

    private:
        Pin _output;
    };
}
