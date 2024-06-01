/*
** EPITECH PROJECT, 2024
** NotComponent.hpp
** File description:
** NotComponent.hpp
*/

#pragma once

#include "nts/components/IComponent.hpp"

namespace nts {
    class NotComponent : public IComponent {
    public:
        NotComponent();
        virtual ~NotComponent() override = default;

        virtual void tick() override;
        virtual Pin& pin(std::size_t pin) override;

    private:
        Pin _input;
        Pin _output;
    };
}
