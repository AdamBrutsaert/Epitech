/*
** EPITECH PROJECT, 2024
** CpuModule.hpp
** File description:
** CpuModule.hpp
*/

#pragma once

#include "IModule.hpp"

namespace Krell {
    class RamModule : public IModule {
    public:
        RamModule();
        virtual ~RamModule() override;

        virtual void update(double deltaTime) override;
        virtual Height render(std::unique_ptr<SFMLDisplay>& display, Width width, HeightOffset offset, bool selected) override;
        virtual Height render(std::unique_ptr<NCursesDisplay>& display, Width width, HeightOffset offset, bool selected) override;

    private:
        void createRAMLineChart(Width width, HeightOffset offset);
        sf::RectangleShape _rectangle;
        sf::RectangleShape _bgRectangle;
        sf::Text _text;
        double _elapsedTime;
        double _memoryUsage;
        unsigned long _freeMemory;
        unsigned long _totalMemory;
        WINDOW* _window;
    };
}
