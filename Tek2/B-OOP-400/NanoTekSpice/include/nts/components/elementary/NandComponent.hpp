/*
** EPITECH PROJECT, 2024
** NandComponent.hpp
** File description:
** NandComponent.hpp
*/

#pragma once

#include "AndComponent.hpp"
#include "NotComponent.hpp"

namespace nts {
    class NandComponent : public IComponent {
    public:
        NandComponent();
        virtual ~NandComponent() override = default;

        virtual void tick() override;
        virtual Pin& pin(std::size_t pin) override;

    private:
        AndComponent _and;
        NotComponent _not;
    };
}
