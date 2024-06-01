/*
** EPITECH PROJECT, 2024
** Playing.hpp
** File description:
** Playing.hpp
*/

#pragma once

#include "arcade/IGame.hpp"
#include "nibbler/entities/Snake.hpp"
#include "nibbler/entities/Apple.hpp"
#include "nibbler/entities/Background.hpp"
#include "nibbler/entities/Map.hpp"

#include "utils/SceneManager.hpp"

#include <vector>

namespace nibbler::scenes {
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
        void _loadMap(arc::ILibrary& lib);
        void _loadSounds(arc::ILibrary& lib);

        void _spawnApple();
        bool _hasWon();

    private:
        uint64_t& _score;
        utils::SceneManager& _sceneManager;

        entities::Map _map;
        entities::Snake _snake;
        std::vector<entities::Apple> _apples;
        entities::Background _background;

        float _gameCooldown;
        float _snakeCooldown;
        float _appleCooldown;
        float _deadCooldown;
        bool _deadSoundPlayed;
    };
};
