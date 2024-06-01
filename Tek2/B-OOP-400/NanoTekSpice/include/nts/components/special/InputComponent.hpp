/*
** EPITECH PROJECT, 2024
** InputComponent.hpp
** File description:
** InputComponent.hpp
*/

#pragma once

#include "nts/components/IComponent.hpp"

namespace nts {
    class InputComponent : public IComponent {
    public:
        InputComponent();
        virtual ~InputComponent() override = default;

        virtual void tick() override;
        virtual Pin& pin(std::size_t pin) override;

    private:
        Pin _output;
    };
}
