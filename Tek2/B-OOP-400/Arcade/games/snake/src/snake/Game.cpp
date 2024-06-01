/*
** EPITECH PROJECT, 2024
** SnakeGame.cpp
** File description:
** SnakeGame.cpp
*/

#include "snake/Game.hpp"
#include "snake/scenes/Playing.hpp"

namespace snake {
    Game::Game()
        : _score(0)
    {
    }

    void Game::initialize([[maybe_unused]] arc::ILibrary &lib)
    {
        this->_sceneManager.switchScene(std::make_shared<scenes::Playing>(this->_score, this->_sceneManager));
    }

    void Game::onKeyPressed(arc::ILibrary &lib, arc::KeyCode key, bool shift)
    {
        this->_sceneManager.onKeyPressed(lib, key, shift);
    }

    void Game::onMouseButtonPressed(arc::ILibrary &lib, arc::MouseButton button, int32_t x, int32_t y)
    {
        this->_sceneManager.onMouseButtonPressed(lib, button, x, y);
    }

    void Game::update(arc::ILibrary &lib, float deltaTime)
    {
        this->_sceneManager.update(lib, deltaTime);
    }

    void Game::draw(arc::ILibrary &lib)
    {
        this->_sceneManager.draw(lib);
    }
}
