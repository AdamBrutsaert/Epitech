#pragma once
#include "raytracer/materials/Color.hpp"

#include <cstddef>
#include <SFML/Graphics.hpp>

namespace rt::core {
    class Display {
    public:
        Display(std::size_t imageWidth, std::size_t imageHeight);
        ~Display() = default;

        /// Initializes the display
        void init();

        /// poolEvent
        void poolEvent();

        // updates pixels
        void updatePixels(const std::vector<rt::materials::Color> pixels);

        /// Updates the scene
        void update();

        /// Closes the display
        void close();

        // Returns the window
        sf::RenderWindow& getWindow() { return this->_window; }

    private:
        sf::RenderWindow _window;
        sf::Texture _texture;
        sf::Sprite _sprite;
        sf::Image _image;

        std::size_t _imageWidth;
        std::size_t _imageHeight;

        std::vector<rt::materials::Color> _pixels;

        void _drawFromPixels();
    };
}
