/*
** EPITECH PROJECT, 2024
** Apple.cpp
** File description:
** Apple.cpp
*/

#include "nibbler/entities/Apple.hpp"

namespace nibbler::entities {
    Apple::Apple(uint32_t x, uint32_t y)
        : _x(x), _y(y)
    {
    }

    void Apple::draw(arc::ILibrary &lib)
    {
        lib.display().draw(lib.textures().get("apple"), this->_x, this->_y);
    }
}
