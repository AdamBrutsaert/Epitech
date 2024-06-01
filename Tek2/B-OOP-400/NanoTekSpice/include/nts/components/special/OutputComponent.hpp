/*
** EPITECH PROJECT, 2024
** OutputComponent.hpp
** File description:
** OutputComponent.hpp
*/

#pragma once

#include "nts/components/IComponent.hpp"

namespace nts {
    class OutputComponent : public IComponent {
    public:
        OutputComponent();
        virtual ~OutputComponent() override = default;

        virtual void tick() override;
        virtual Pin& pin(std::size_t pin) override;

    private:
        Pin _input;
    };
}
