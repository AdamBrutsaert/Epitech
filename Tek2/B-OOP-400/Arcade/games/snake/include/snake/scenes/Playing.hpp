/*
** EPITECH PROJECT, 2024
** Playing.hpp
** File description:
** Playing.hpp
*/

#pragma once

#include "arcade/IGame.hpp"
#include "snake/entities/Snake.hpp"
#include "snake/entities/Apple.hpp"
#include "snake/entities/Background.hpp"

#include "utils/SceneManager.hpp"

#include <vector>

namespace snake::scenes {
    constexpr uint32_t MAP_WIDTH = 15;
    constexpr uint32_t MAP_HEIGHT = 15;

    class Playing : public arc::IGame {
    public:
        Playing(uint64_t& score, utils::SceneManager& sceneManager);
        virtual ~Playing() = default;

        virtual void initialize(arc::ILibrary& lib);
        virtual void onKeyPressed(arc::ILibrary& lib, arc::KeyCode key, bool shift);
        virtual void onMouseButtonPressed(arc::ILibrary& lib, arc::MouseButton button, int32_t x, int32_t y);
        virtual void update(arc::ILibrary& lib, float deltaTime);
        virtual void draw(arc::ILibrary& lib);
        inline virtual uint64_t score() const { return 0; }

    private:
        void _loadBackground(arc::ILibrary& lib);
        void _loadApple(arc::ILibrary& lib);
        void _loadSnake(arc::ILibrary& lib);
        void _loadSounds(arc::ILibrary& lib);
        void _spawnApple();

    private:
        uint64_t& _score;
        utils::SceneManager& _sceneManager;

        entities::Snake _snake;
        std::vector<entities::Apple> _apples;
        entities::Background _background;

        float _snakeCooldown;
        float _appleCooldown;
        float _deadCooldown;
        bool _deadSoundPlayed;
    };
};
