/*
** EPITECH PROJECT, 2024
** OrComponent.hpp
** File description:
** OrComponent.hpp
*/

#pragma once

#include "nts/components/IComponent.hpp"

namespace nts {
    class OrComponent : public IComponent {
    public:
        OrComponent();
        virtual ~OrComponent() override = default;

        virtual void tick() override;
        virtual Pin& pin(std::size_t pin) override;

    private:
        Pin _input1;
        Pin _input2;
        Pin _output;
    };
}
