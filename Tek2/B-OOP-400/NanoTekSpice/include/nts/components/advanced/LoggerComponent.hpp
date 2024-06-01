/*
** EPITECH PROJECT, 2024
** LoggerComponent.hpp
** File description:
** LoggerComponent.hpp
*/

#pragma once

#include "nts/components/IComponent.hpp"

#include <fstream>

namespace nts {
    class LoggerComponent : public IComponent {
    public:
        LoggerComponent();
        virtual ~LoggerComponent() override = default;

        virtual void tick() override;
        virtual Pin& pin(std::size_t pin) override;

    private:
        std::ofstream _file;
        std::vector<Pin> _inputs;
        Pin _clock;
        Pin _inhibit;
    };
}
