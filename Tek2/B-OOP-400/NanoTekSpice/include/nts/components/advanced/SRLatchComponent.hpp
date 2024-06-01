/*
** EPITECH PROJECT, 2024
** SRLatch.hpp
** File description:
** SRLatch.hpp
*/

#pragma once

#include "nts/components/elementary/NorComponent.hpp"

namespace nts {
    class SRLatchComponent : public IComponent {
    public:
        SRLatchComponent();
        virtual ~SRLatchComponent() override = default;

        virtual void tick() override;
        virtual Pin& pin(std::size_t pin) override;

    private:
        NorComponent _nor1;
        NorComponent _nor2;
    };
}
