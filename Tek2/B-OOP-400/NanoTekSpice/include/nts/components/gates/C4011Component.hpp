/*
** EPITECH PROJECT, 2024
** C4011Component.hpp
** File description:
** C4011Component.hpp
*/

#pragma once

#include "nts/components/elementary/NandComponent.hpp"

namespace nts {
    class C4011Component : public IComponent {
    public:
        C4011Component() = default;
        virtual ~C4011Component() override = default;

        virtual void tick() override;
        virtual Pin& pin(std::size_t pin) override;

    private:
        NandComponent _nand1;
        NandComponent _nand2;
        NandComponent _nand3;
        NandComponent _nand4;
    };
}
