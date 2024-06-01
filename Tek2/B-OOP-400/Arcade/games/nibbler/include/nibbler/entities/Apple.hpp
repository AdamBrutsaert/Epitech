/*
** EPITECH PROJECT, 2024
** Apple.hpp
** File description:
** Apple.hpp
*/

#pragma once

#include "arcade/ILibrary.hpp"

namespace nibbler::entities {
    class Apple {
    public:
        Apple(uint32_t x, uint32_t y);
        ~Apple() = default;

        inline uint32_t x() const { return this->_x; }
        inline uint32_t y() const { return this->_y; }

        void draw(arc::ILibrary& lib);

    private:
        uint32_t _x;
        uint32_t _y;
    };
}
