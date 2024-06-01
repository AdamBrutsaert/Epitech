/*
** EPITECH PROJECT, 2024
** Selection.cpp
** File description:
** Selection.cpp
*/

#include "selection/Game.hpp"
#include "Core.hpp"

#include <cmath>

namespace core::selection {
    Game::Game(Core& core)
        : _state(State::GAME),
          _scoreSelection(core),
          _gameSelection(core), _librarySelection(core)
    {
    }

    void Game::initialize(arc::ILibrary& lib)
    {
        lib.display().setTitle("Core");
        lib.display().setFramerate(60);
        lib.display().setTileSize(16);
        lib.display().setWidth(40);
        lib.display().setHeight(40);

        // Loading fonts
        arc::FontSpecification font;
        font.path = "assets/core/Roboto-Regular.ttf";
        font.size = 16;
        font.color = arc::Color{255, 255, 255, 255};
        lib.fonts().load("regular", font);

        font.color = arc::Color{0, 255, 0, 255};
        lib.fonts().load("selected", font);

        font.color = arc::Color{255, 0, 0, 255};
        lib.fonts().load("focus", font);

        // Loading textures
        for (uint32_t i = 0; i < 9; i++) {
            uint32_t line = i / 3;
            uint32_t column = i % 3;

            arc::TextureSpecification texture;
            texture.textual = {.character = ' ', .color = {0, 0, 0, 0}};
            texture.graphical = arc::TextureImage{
                .path = "assets/core/steel.png",
                .subrect = arc::URect{
                    .x = column * 16u,
                    .y = line * 16u,
                    .width = 16u,
                    .height = 16u
                }
            };

            lib.textures().load("steel_" + std::to_string(i), texture);
        }
    }

    void Game::onKeyPressed(arc::ILibrary& lib, arc::KeyCode key, bool shift)
    {
        // If the key is TAB, we switch the state
        if (key == arc::KeyCode::TAB) {
            switch (_state) {
            case State::USERNAME:
                _state = State::SCORE;
                lib.display().setTitle("Core - Watching score");
                break;
            case State::SCORE:
                _state = State::GAME;
                lib.display().setTitle("Core - Choosing game");
                break;
            case State::GAME:
                _state = State::LIBRARY;
                lib.display().setTitle("Core - Choosing library");
                break;
            case State::LIBRARY:
                _state = State::USERNAME;
                lib.display().setTitle("Core - Setting username");
                break;
            }
            return;
        }

        // Else we forward the key to the current state
        switch (_state) {
        case State::USERNAME:
            _usernameSelection.onKeyPressed(lib, key, shift);
            break;
        case State::SCORE:
            _scoreSelection.onKeyPressed(lib, key, shift);
            break;
        case State::GAME:
            _gameSelection.onKeyPressed(lib, key, shift);
            break;
        case State::LIBRARY:
            _librarySelection.onKeyPressed(lib, key, shift);
            break;
        }
    }

    void Game::onMouseButtonPressed(arc::ILibrary& lib, arc::MouseButton button, int32_t x, int32_t y)
    {
        (void)lib;
        (void)button;
        (void)x;
        (void)y;
    }

    void Game::update(arc::ILibrary& lib, float deltaTime)
    {
        (void)lib;
        (void)deltaTime;
    }

    void Game::draw(arc::ILibrary& lib)
    {
        lib.display().clear();

        float half_width = lib.display().width() / 2.0f;
        float half_height = lib.display().height() / 2.0f;

        this->_drawBackground(lib, 0, 0, std::ceil(half_width), std::ceil(half_height));
        this->_drawBackground(lib, std::ceil(half_width), 0, std::floor(half_width), std::ceil(half_height));
        this->_drawBackground(lib, 0, std::ceil(half_height), std::ceil(half_width), std::floor(half_height));
        this->_drawBackground(lib, std::ceil(half_width), std::ceil(half_height), std::floor(half_width), std::floor(half_height));

        this->_usernameSelection.draw(lib, this->_state == State::USERNAME);
        this->_scoreSelection.draw(lib, this->_state == State::SCORE);
        this->_gameSelection.draw(lib, this->_state == State::GAME);
        this->_librarySelection.draw(lib, this->_state == State::LIBRARY);
        lib.display().flush();
    }

    void Game::_drawBackground(arc::ILibrary& lib, uint32_t x, uint32_t y, uint32_t width, uint32_t height)
    {
        for (uint32_t i = 0; i < width * height; i++) {
            uint32_t line = i / width;
            uint32_t column = i % width;

            std::shared_ptr<arc::ITexture> texture;

            if (line == 0 && column == 0) texture = lib.textures().get("steel_0");
            else if (line == 0 && column == width - 1) texture = lib.textures().get("steel_2");
            else if (line == height - 1 && column == 0) texture = lib.textures().get("steel_6");
            else if (line == height - 1 && column == width - 1) texture = lib.textures().get("steel_8");
            else if (line == 0) texture = lib.textures().get("steel_1");
            else if (line == height - 1) texture = lib.textures().get("steel_7");
            else if (column == 0) texture = lib.textures().get("steel_3");
            else if (column == width - 1) texture = lib.textures().get("steel_5");
            else texture = lib.textures().get("steel_4");

            lib.display().draw(texture, x + column, y + line);
        }
    }
};
