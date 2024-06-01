#include "raytracer/core/Display.hpp"
#include "raytracer/materials/Color.hpp"
#include "raytracer/maths/Interval.hpp"

#include <SFML/Graphics.hpp>

namespace rt::core {

    Display::Display(std::size_t imageWidth, std::size_t imageHeight)
    {
        this->_imageWidth = imageWidth;
        this->_imageHeight = imageHeight;
        this->init();
    }


    void Display::init() {
        this->_window.create(sf::VideoMode(this->_imageWidth, this->_imageHeight), "Raytracer");
        this->_texture.create(this->_imageWidth, this->_imageHeight);
        this->_sprite.setTexture(this->_texture);
        this->_image.create(this->_imageWidth, this->_imageHeight, sf::Color::Black);
    }

    void Display::poolEvent()
    {
        sf::Event event;

        while (this->_window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                this->_window.close();
            }
        }
    }

    void Display::update()
    {
        this->_window.clear();
        this->_texture.update(this->_image);
        this->_window.draw(this->_sprite);
        this->_window.display();
    }

    void Display::_drawFromPixels()
    {
        for (std::size_t y = 0; y < this->_imageHeight; y++) {
            for (std::size_t x = 0; x < this->_imageWidth; x++) {
                auto& pixel = this->_pixels[y * this->_imageWidth + x];
                auto [rbyte, gbyte, bbyte] = rt::materials::ColorToRGB(pixel);


                this->_image.setPixel(x, y, sf::Color(
                    static_cast<sf::Uint8>(rbyte),
                    static_cast<sf::Uint8>(gbyte),
                    static_cast<sf::Uint8>(bbyte)
                ));
            }
        }
    }

    void Display::updatePixels(const std::vector<rt::materials::Color> pixels)
    {
        this->_pixels = pixels;
        this->_drawFromPixels();
    }

    void Display::close()
    {
        this->_window.close();
    }
}
