/*
** EPITECH PROJECT, 2024
** NorComponent.hpp
** File description:
** NorComponent.hpp
*/

#pragma once

#include "OrComponent.hpp"
#include "NotComponent.hpp"

namespace nts {
    class NorComponent : public IComponent {
    public:
        NorComponent();
        virtual ~NorComponent() override = default;

        virtual void tick() override;
        virtual Pin& pin(std::size_t pin) override;

    private:
        OrComponent _or;
        NotComponent _not;
    };
}
