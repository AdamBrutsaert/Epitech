/*
** EPITECH PROJECT, 2024
** AndComponent.hpp
** File description:
** AndComponent.hpp
*/

#pragma once

#include "nts/components/IComponent.hpp"

namespace nts {
    class AndComponent : public IComponent {
    public:
        AndComponent();
        virtual ~AndComponent() override = default;

        virtual void tick() override;
        virtual Pin& pin(std::size_t pin) override;

    private:
        Pin _input1;
        Pin _input2;
        Pin _output;
    };
}
