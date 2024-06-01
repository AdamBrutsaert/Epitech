/*
** EPITECH PROJECT, 2024
** IComponent.hpp
** File description:
** IComponent.hpp
*/

#pragma once

#include "Pin.hpp"

namespace nts {
    class IComponent {
    public:
        class InvalidPin : public std::exception {};

    public:
        virtual ~IComponent() = default;

        virtual void tick() = 0;
        virtual Pin& pin(std::size_t pin) = 0;
    };
}
