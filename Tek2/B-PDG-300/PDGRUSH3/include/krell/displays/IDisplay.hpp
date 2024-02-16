/*
** EPITECH PROJECT, 2024
** IDisplay.hpp
** File description:
** IDisplay.hpp
*/

#pragma once

#include "../core/Types.hpp"

#include <SFML/Window/Keyboard.hpp>
#include <functional>

namespace Krell {
    class IDisplay {
    public:
        virtual ~IDisplay() = default;

        virtual void close() = 0;
        virtual bool shouldClose() const = 0;
        virtual void pollEvents() = 0;
        virtual void clear() = 0;
        virtual void forceClear() = 0;
        virtual void display() = 0;

        virtual Width getWidth() const = 0;

        void onKeyReleased(sf::Keyboard::Key key) { if (this->_onKeyReleased) this->_onKeyReleased(key); }
        void setOnKeyReleased(std::function<void(sf::Keyboard::Key)> onKeyPressed) { this->_onKeyReleased = onKeyPressed; }

    private:
        std::function<void(sf::Keyboard::Key)> _onKeyReleased;
    };
}
