/*
** EPITECH PROJECT, 2024
** Game.hpp
** File description:
** Game.hpp
*/

#pragma once

#include "arcade/IGame.hpp"
#include "utils/SceneManager.hpp"

namespace nibbler {
    class Game : public arc::IGame {
    public:
        Game();
        virtual ~Game() = default;

        virtual void initialize(arc::ILibrary& lib);
        virtual void onKeyPressed(arc::ILibrary& lib, arc::KeyCode key, bool shift);
        virtual void onMouseButtonPressed(arc::ILibrary& lib, arc::MouseButton button, int32_t x, int32_t y);
        virtual void update(arc::ILibrary& lib, float deltaTime);
        virtual void draw(arc::ILibrary& lib);
        inline virtual uint64_t score() const { return this->_score; }

    private:
        utils::SceneManager _sceneManager;
        uint64_t _score;
    };
}
