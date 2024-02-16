/*
** EPITECH PROJECT, 2024
** CpuModule.hpp
** File description:
** CpuModule.hpp
*/

#pragma once

#include "IModule.hpp"
#include <vector>

namespace Krell {
    class CpuModule : public IModule {
    public:
        CpuModule();
        virtual ~CpuModule() override;

        virtual void update(double deltaTime) override;
        virtual Height render(std::unique_ptr<SFMLDisplay>& display, Width width, HeightOffset offset, bool selected) override;
        virtual Height render(std::unique_ptr<NCursesDisplay>& display, Width width, HeightOffset offset, bool selected) override;

    private:
        void computeCpuCoreCount();
        void computeCpuUsage();
        void printCoreLine(Width width, HeightOffset offset, double percentage, const std::string& name);

    private:
        struct CoreInfo {
            double usage;
            unsigned long long prevIdle;
            unsigned long long prevTotal;
        };

    private:
        double _elapsedTime;

        // CPU Info
        std::size_t _physicalCores;
        std::size_t _virtualCores;

        CoreInfo _cpuInfo;
        std::vector<CoreInfo> _coreInfos;

        // SFML
        sf::RectangleShape _rectangle;
        sf::RectangleShape _bgRectangle;
        sf::Text _text;

        // NCurses
        WINDOW* _window;
    };
}
