/*
** EPITECH PROJECT, 2024
** SFMLDisplay.hpp
** File description:
** SFMLDisplay.hpp
*/

#pragma once

#include "IDisplay.hpp"

#include <SFML/Graphics.hpp>

namespace Krell {
    class SFMLDisplay : public IDisplay {
    public:
        SFMLDisplay();
        ~SFMLDisplay() override = default;

        virtual void close() override;
        virtual bool shouldClose() const override;
        virtual void pollEvents() override;
        virtual void clear() override;
        virtual void forceClear() override;
        virtual void display() override;

        virtual Width getWidth() const override;
        sf::RenderTarget& getRenderTarget();
        sf::Font &getFont();

    private:
        sf::RenderWindow _window;
        sf::Font _font;
    };
}
