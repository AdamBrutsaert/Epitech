/*
** EPITECH PROJECT, 2024
** Snake.cpp
** File description:
** Snake.cpp
*/

#include "snake/entities/Snake.hpp"

namespace snake::entities {
    Snake::Snake(uint32_t mapWidth, uint32_t mapHeight)
        : _mapWidth(mapWidth), _mapHeight(mapHeight),
          _direction(Direction::RIGHT), _growth(0), _dead(false)
    {
        this->_body.push_back(Position{mapWidth / 2 - 2, mapHeight / 2});
        this->_body.push_back(Position{mapWidth / 2 - 1, mapHeight / 2});
        this->_body.push_back(Position{mapWidth / 2, mapHeight / 2});
        this->_body.push_back(Position{mapWidth / 2 + 1, mapHeight / 2});
    }

    bool Snake::collides(uint32_t x, uint32_t y) const
    {
        for (const auto &part : this->_body) {
            if (part.x == x && part.y == y)
                return true;
        }
        return false;
    }

    void Snake::move()
    {
        if (this->_dead)
            return;

        // Take the next input
        if (!this->_inputs.empty()) {
            this->_direction = this->_inputs.front();
            this->_inputs.pop_front();
        }

        int32_t x = this->_body.back().x;
        int32_t y = this->_body.back().y;

        // Get next position
        switch (this->_direction) {
        case Direction::UP:
            y -= 1;
            break;
        case Direction::DOWN:
            y += 1;
            break;
        case Direction::LEFT:
            x -= 1;
            break;
        case Direction::RIGHT:
            x += 1;
            break;
        };

        // Check if the next position is in the wall
        if (x < 0 || x >= (int32_t)this->_mapWidth || y < 0 || y >= (int32_t)this->_mapHeight) {
            this->_dead = true;
            return;
        }

        // Check if the snake collides with itself
        for (size_t i = this->_growth == 0; i < this->_body.size(); i++) {
            if (this->_body[i].x == (uint32_t)x && this->_body[i].y == (uint32_t)y) {
                this->_dead = true;
                return;
            }
        }

        // Pop tail
        if (this->_growth > 0) {
            this->_growth -= 1;
        } else {
            this->_body.pop_front();
        }

        this->_body.push_back({ (uint32_t)x, (uint32_t)y });
    }

    static bool IsValidTurn(Direction current, Direction next)
    {
        if (current == next)
            return false;

        switch (next) {
        case Direction::UP: return current != Direction::DOWN;
        case Direction::DOWN: return current != Direction::UP;
        case Direction::LEFT: return current != Direction::RIGHT;
        case Direction::RIGHT: return current != Direction::LEFT;
        }
        return false;
    }

    void Snake::turn(Direction direction)
    {
        if (this->_inputs.size() == 0) {
            if (IsValidTurn(this->_direction, direction))
                this->_inputs.push_back(direction);
        } else if (this->_inputs.size() < MAX_BUFFERED_INPUTS) {
            if (IsValidTurn(this->_inputs.back(), direction))
                this->_inputs.push_back(direction);
        }
    }

    void Snake::grow()
    {
        this->_growth += 1;
    }

    static Direction GetDirection(Position a, Position b)
    {
        int32_t x = (int32_t)b.x - (int32_t)a.x;
        int32_t y = (int32_t)b.y - (int32_t)a.y;

        if (x == 1) return Direction::RIGHT;
        if (x == -1) return Direction::LEFT; 
        if (y == 1) return Direction::DOWN;
        return Direction::UP;
    }

    static std::shared_ptr<arc::ITexture> GetHeadTexture(arc::ILibrary &lib, std::deque<Position> body)
    {
        auto direction = GetDirection(body[body.size() - 2], body[body.size() - 1]);

        if (direction == Direction::LEFT) return lib.textures().get("head_left");
        if (direction == Direction::RIGHT) return lib.textures().get("head_right");
        if (direction == Direction::UP) return lib.textures().get("head_top");
        return lib.textures().get("head_bottom");
    }

    static std::shared_ptr<arc::ITexture> GetTailTexture(arc::ILibrary &lib, std::deque<Position> body)
    {
        auto direction = GetDirection(body[0], body[1]);

        if (direction == Direction::LEFT) return lib.textures().get("tail_left");
        if (direction == Direction::RIGHT) return lib.textures().get("tail_right");
        if (direction == Direction::UP) return lib.textures().get("tail_top");
        return lib.textures().get("tail_bottom");
    }

    static std::shared_ptr<arc::ITexture> GetBodyTexture(arc::ILibrary &lib, std::deque<Position> body, size_t i)
    {
        auto d1 = GetDirection(body[i - 1], body[i]);
        auto d2 = GetDirection(body[i], body[i + 1]);

        if (d1 == Direction::RIGHT && d2 == Direction::RIGHT) return lib.textures().get("body_top");
        if (d1 == Direction::LEFT && d2 == Direction::LEFT) return lib.textures().get("body_top");
        if (d1 == Direction::UP && d2 == Direction::UP) return lib.textures().get("body_right");
        if (d1 == Direction::DOWN && d2 == Direction::DOWN) return lib.textures().get("body_right");

        if (d1 == Direction::RIGHT && d2 == Direction::UP) return lib.textures().get("body_bottomright");
        if (d1 == Direction::UP && d2 == Direction::RIGHT) return lib.textures().get("body_topleft");
        
        if (d1 == Direction::RIGHT && d2 == Direction::DOWN) return lib.textures().get("body_topright");
        if (d1 == Direction::DOWN && d2 == Direction::RIGHT) return lib.textures().get("body_left");

        if (d1 == Direction::LEFT && d2 == Direction::UP) return lib.textures().get("body_left");
        if (d1 == Direction::UP && d2 == Direction::LEFT) return lib.textures().get("body_topright");

        if (d1 == Direction::LEFT && d2 == Direction::DOWN) return lib.textures().get("body_topleft");
        if (d1 == Direction::DOWN && d2 == Direction::LEFT) return lib.textures().get("body_bottomright");

        return nullptr;
    }

    void Snake::draw(arc::ILibrary &lib)
    {
        if (this->_body.size() > 0)
            lib.display().draw(GetTailTexture(lib, this->_body), this->_body.front().x, this->_body.front().y);

        for (size_t i = 1; i + 1 < this->_body.size(); i++)
            lib.display().draw(GetBodyTexture(lib, this->_body, i), this->_body[i].x, this->_body[i].y);

        if (this->_body.size() > 0)
            lib.display().draw(GetHeadTexture(lib, this->_body), this->_body.back().x, this->_body.back().y);
    }

    std::vector<Position> Snake::available() const
    {
        std::vector<Position> available;

        for (uint32_t x = 0; x < this->_mapWidth; x++) {
            for (uint32_t y = 0; y < this->_mapHeight; y++) {
                if (!this->collides(x, y)) {
                    available.push_back(Position{x, y});
                }
            }
        }

        return available;
    }
}
