/*
** EPITECH PROJECT, 2024
** SFMLDisplay.cpp
** File description:
** SFMLDisplay.cpp
*/

#include "krell/displays/SFMLDisplay.hpp"

namespace Krell {
    SFMLDisplay::SFMLDisplay()
        : _window(sf::VideoMode(500, 720), "MyGKrellm")
    {
        this->_font.loadFromFile("assets/ComicSansMS3.ttf");
        this->_window.setFramerateLimit(60);
    }

    void SFMLDisplay::close()
    {
        this->_window.close();
    }

    bool SFMLDisplay::shouldClose() const
    {
        return !this->_window.isOpen();
    }

    void SFMLDisplay::pollEvents()
    {
        sf::Event event;

        while (this->_window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                this->_window.close();
            if (event.type == sf::Event::Resized) {
                sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
                this->_window.setView(sf::View(visibleArea));
            }
            if (event.type == sf::Event::KeyReleased)
                this->onKeyReleased(event.key.code);
        }
    }

    void SFMLDisplay::clear()
    {
        _window.clear();
    }

    void SFMLDisplay::forceClear()
    {
        _window.clear();
    }

    void SFMLDisplay::display()
    {
        _window.display();
    }

    Width SFMLDisplay::getWidth() const
    {
        return this->_window.getSize().x;
    }

    sf::RenderTarget& SFMLDisplay::getRenderTarget()
    {
        return this->_window;
    }

    sf::Font& SFMLDisplay::getFont()
    {
        return this->_font;
    }
}
