/*
** EPITECH PROJECT, 2024
** Selection.hpp
** File description:
** Selection.hpp
*/

#pragma once

#include "arcade/IGame.hpp"

#include "State.hpp"
#include "UsernameSelection.hpp"
#include "ScoreSelection.hpp"
#include "GameSelection.hpp"
#include "LibrarySelection.hpp"

namespace core {
    class Core;
}

namespace core::selection {
    class Game : public arc::IGame {
    public:
        Game(Core& core);
        virtual ~Game() = default;

        virtual void initialize(arc::ILibrary& lib) override;
        virtual void onKeyPressed(arc::ILibrary& lib, arc::KeyCode key, bool shift) override;
        virtual void onMouseButtonPressed(arc::ILibrary& lib, arc::MouseButton button, int32_t x, int32_t y) override;
        virtual void update(arc::ILibrary& lib, float deltaTime) override;
        virtual void draw(arc::ILibrary& lib) override;
        virtual uint64_t score() const override { return 0; }

        inline std::string username() const { return _usernameSelection.username(); }

    private:
        void _drawBackground(arc::ILibrary& lib, uint32_t x, uint32_t y, uint32_t width, uint32_t height);

    private:
        selection::State _state;
        selection::UsernameSelection _usernameSelection;
        selection::ScoreSelection _scoreSelection;
        selection::GameSelection _gameSelection;
        selection::LibrarySelection _librarySelection;
    };
};
