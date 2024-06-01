/*
** EPITECH PROJECT, 2024
** Win.hpp
** File description:
** Win.hpp
*/

#pragma once

#include "arcade/IGame.hpp"
#include "utils/SceneManager.hpp"

namespace nibbler::scenes {
    class Win : public arc::IGame {
    public:
        Win(uint64_t& score, utils::SceneManager& sceneManager);
        virtual ~Win() = default;

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
