/*
** EPITECH PROJECT, 2024
** Scene.hpp
** File description:
** Scene.hpp
*/

#pragma once

#include "arcade/IGame.hpp"

namespace utils {
    class SceneManager {
    public:
        SceneManager() = default;
        ~SceneManager() = default;

        void onKeyPressed(arc::ILibrary& lib, arc::KeyCode key, bool shift);
        void onMouseButtonPressed(arc::ILibrary& lib, arc::MouseButton button, int32_t x, int32_t y);
        void update(arc::ILibrary& lib, float deltaTime);
        void draw(arc::ILibrary& lib);

        void switchScene(std::shared_ptr<arc::IGame> scene);

    private:
        std::shared_ptr<arc::IGame> _currentScene;
        std::shared_ptr<arc::IGame> _nextScene;
    };
}
