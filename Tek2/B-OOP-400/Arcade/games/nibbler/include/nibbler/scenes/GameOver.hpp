/*
** EPITECH PROJECT, 2024
** GameOver.hpp
** File description:
** GameOver.hpp
*/

#pragma once

#include "arcade/IGame.hpp"
#include "utils/SceneManager.hpp"

namespace nibbler::scenes {
    class GameOver : public arc::IGame {
    public:
        GameOver(uint64_t& score, utils::SceneManager& sceneManager);
        virtual ~GameOver() = default;

        virtual void initialize(arc::ILibrary& lib);
        virtual void onKeyPressed(arc::ILibrary& lib, arc::KeyCode key, bool shift);
        virtual void onMouseButtonPressed(arc::ILibrary& lib, arc::MouseButton button, int32_t x, int32_t y);
        virtual void update(arc::ILibrary& lib, float deltaTime);
        virtual void draw(arc::ILibrary& lib);
        inline virtual uint64_t score() const { return 0; }

    private:
        uint64_t& _score;
        utils::SceneManager& _sceneManager;
    };
};
