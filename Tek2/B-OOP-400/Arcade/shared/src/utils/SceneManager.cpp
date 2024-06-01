/*
** EPITECH PROJECT, 2024
** Scene.cpp
** File description:
** Scene.cpp
*/

#include "utils/SceneManager.hpp"

namespace utils {
    void SceneManager::onKeyPressed(arc::ILibrary& lib, arc::KeyCode key, bool shift)
    {
        if (this->_currentScene != nullptr)
            this->_currentScene->onKeyPressed(lib, key, shift);
    }

    void SceneManager::onMouseButtonPressed(arc::ILibrary& lib, arc::MouseButton button, int32_t x, int32_t y)
    {
        if (this->_currentScene != nullptr)
            this->_currentScene->onMouseButtonPressed(lib, button, x, y);
    }

    void SceneManager::update(arc::ILibrary& lib, float deltaTime)
    {
        if (this->_currentScene != nullptr)
            this->_currentScene->update(lib, deltaTime);

        if (this->_nextScene != nullptr) {
            this->_currentScene = this->_nextScene;
            this->_nextScene = nullptr;
            this->_currentScene->initialize(lib);
        }
    }

    void SceneManager::draw(arc::ILibrary& lib)
    {
        if (this->_currentScene != nullptr)
            this->_currentScene->draw(lib);
    }

    void SceneManager::switchScene(std::shared_ptr<arc::IGame> scene)
    {
        this->_nextScene = scene;
    }
}
