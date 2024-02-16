/*
** EPITECH PROJECT, 2024
** IModule.hpp
** File description:
** IModule.hpp
*/

#pragma once

#include "../displays/SFMLDisplay.hpp"
#include "../displays/NCursesDisplay.hpp"
#include "../core/Types.hpp"

#include <memory>

namespace Krell {
    class IModule {
    public:
        virtual ~IModule() = default;

        virtual void update(double deltaTime) = 0;
        virtual Height render(std::unique_ptr<Krell::SFMLDisplay>& display, Width width, HeightOffset offset, bool selected) = 0;
        virtual Height render(std::unique_ptr<Krell::NCursesDisplay>& display, Width width, HeightOffset offset, bool selected) = 0;

    private:
        bool _isSelected = false;
    };
}
