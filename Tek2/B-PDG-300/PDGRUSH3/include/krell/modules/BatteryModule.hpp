/*
** EPITECH PROJECT, 2024
** BatteryModule.hpp
** File description:
** BatteryModule.hpp
*/

#pragma once

#include "IModule.hpp"

#include <optional>

namespace Krell {
    class BatteryModule : public IModule {
    public:
        BatteryModule();
        virtual ~BatteryModule() override;

        virtual void update(double deltaTime) override;
        virtual Height render(std::unique_ptr<SFMLDisplay>& display, Width width, HeightOffset offset, bool selected) override;
        virtual Height render(std::unique_ptr<NCursesDisplay>& display, Width width, HeightOffset offset, bool selected) override;

    private:
        void createBatteryLineChart(Width width, HeightOffset offset, double percentage, const std::string& name);
        std::optional<uint64_t> _battery;

        WINDOW* _window;
        sf::RectangleShape _rectangle;
        sf::RectangleShape _bgRectangle;
        sf::Text _text;
        sf::Sprite _sprite;
        sf::Texture _texture;
        std::string _batteryStatus;
    };
}
