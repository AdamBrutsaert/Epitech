/*
** EPITECH PROJECT, 2024
** C3NandComponent.hpp
** File description:
** C3NandComponent.hpp
*/

#pragma once

#include "nts/components/IComponent.hpp"

namespace nts {
    class C3NandComponent : public IComponent {
    public:
        C3NandComponent();
        virtual ~C3NandComponent() override = default;

        virtual void tick() override;
        virtual Pin& pin(std::size_t pin) override;

    private:
        void update();

    private:
        Pin _input1;
        Pin _input2;
        Pin _input3;
        Pin _output;
    };
}
