/*
** EPITECH PROJECT, 2024
** NCursesDisplay.hpp
** File description:
** NCursesDisplay.hpp
*/

#pragma once

#include "IDisplay.hpp"

#include <ncurses.h>
#include <SFML/System/Clock.hpp>

namespace Krell {
    class NCursesDisplay : public IDisplay {
    public:
        NCursesDisplay();
        ~NCursesDisplay() override;

        virtual void close() override;
        virtual void forceClear() override;
        virtual bool shouldClose() const override;
        virtual void pollEvents() override;
        virtual void clear() override;
        virtual void display() override;

        virtual Width getWidth() const override;
    private:
        bool _shouldClose;

    private:
        sf::Clock _clock;
        sf::Keyboard::Key _mapKey(int key) const;
    };
}
