/*
** EPITECH PROJECT, 2024
** Map.hpp
** File description:
** Map.hpp
*/

#pragma once

#include "arcade/ILibrary.hpp"

#include <vector>

namespace nibbler::entities {

    enum class Tile {
        EMPTY,
        WALL,
    };

    class Map {
    public:
        Map();
        ~Map() = default;

        void draw(arc::ILibrary& lib);
        inline Tile get(uint32_t x, uint32_t y) const { return _tiles[y][x]; }

        inline uint32_t width() const { return _width; }
        inline uint32_t height() const { return _height; }

    private:
        std::vector<std::vector<Tile>> _tiles;
        uint32_t _width;
        uint32_t _height;
    };
}
