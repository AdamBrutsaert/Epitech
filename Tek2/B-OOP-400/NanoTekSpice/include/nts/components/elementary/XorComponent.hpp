/*
** EPITECH PROJECT, 2024
** XorComponent.hpp
** File description:
** XorComponent.hpp
*/

#pragma once

#include "nts/components/IComponent.hpp"

namespace nts {
    class XorComponent : public IComponent {
    public:
        XorComponent();
        virtual ~XorComponent() override = default;

        virtual void tick() override;
        virtual Pin& pin(std::size_t pin) override;

    private:
        Pin _input1;
        Pin _input2;
        Pin _output;
    };
}
