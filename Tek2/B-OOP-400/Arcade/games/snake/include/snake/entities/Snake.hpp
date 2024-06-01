/*
** EPITECH PROJECT, 2024
** Snake.hpp
** File description:
** Snake.hpp
*/

#pragma once

#include "arcade/ILibrary.hpp"

#include <cstdint>
#include <deque>
#include <vector>

namespace snake::entities {
    struct Position {
        uint32_t x;
        uint32_t y;
    };

    enum class Direction {
        UP,
        DOWN,
        LEFT,
        RIGHT
    };

    constexpr uint32_t MAX_BUFFERED_INPUTS = 2;

    class Snake {
    public:
        Snake(uint32_t mapWidth, uint32_t mapHeight);
        ~Snake() = default;

        bool collides(uint32_t x, uint32_t y) const;
        inline bool dead() const { return this->_dead; }
        inline size_t size() const { return this->_body.size(); }

        void move();
        void turn(Direction direction);
        void grow();

        void draw(arc::ILibrary& lib);
        std::vector<Position> available() const;

    private:
        uint32_t _mapWidth;
        uint32_t _mapHeight;

        std::deque<Position> _body;
        Direction _direction;
        uint32_t _growth;
        bool _dead;

        std::deque<Direction> _inputs;
    };
}
