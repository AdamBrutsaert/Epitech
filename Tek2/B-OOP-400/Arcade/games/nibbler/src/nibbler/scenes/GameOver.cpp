/*
** EPITECH PROJECT, 2024
** GameOver.cpp
** File description:
** GameOver.cpp
*/

#include "nibbler/scenes/GameOver.hpp"
#include "nibbler/scenes/Playing.hpp"

namespace nibbler::scenes {
    GameOver::GameOver(uint64_t& score, utils::SceneManager& sceneManager)
        : _score(score), _sceneManager(sceneManager)
    {
    }

    void GameOver::initialize([[maybe_unused]] arc::ILibrary& lib)
    {
        // Display
        lib.display().setTitle("Nibbler - Game Over");
        lib.display().setFramerate(60);
        lib.display().setTileSize(16);
        lib.display().setWidth(30);
        lib.display().setHeight(30);

        // Fonts
        arc::FontSpecification font;
        font.path = "assets/snake/fonts/roboto.ttf";
        font.size = 32;
        font.color = arc::Color{255, 0, 0, 255};
        lib.fonts().load("title", font);

        font.size = 16;
        font.color = arc::Color{255, 255, 255, 255};
        lib.fonts().load("subtitle", font);
    }

    void GameOver::onKeyPressed([[maybe_unused]] arc::ILibrary& lib, [[maybe_unused]] arc::KeyCode key, bool shift)
    {
        if (shift) return;
        this->_sceneManager.switchScene(std::make_shared<Playing>(this->_score, this->_sceneManager));
    }

    void GameOver::onMouseButtonPressed(arc::ILibrary &lib, arc::MouseButton button, int32_t x, int32_t y)
    {
        (void)lib;
        (void)button;
        (void)x;
        (void)y;
    }

    void GameOver::update([[maybe_unused]] arc::ILibrary &lib, float deltaTime)
    {
        (void)lib;
        (void)deltaTime;
    }

    void GameOver::draw(arc::ILibrary &lib)
    {
        lib.display().clear(arc::Color{0, 0, 0, 255});

        auto hitbox = lib.display().measure("Game Over", lib.fonts().get("title"), 0, 0);
        float x = (lib.display().width() - hitbox.width) / 2.0f;
        float y = (lib.display().height() - hitbox.height) / 2.0f - 2;
        lib.display().print("Game Over", lib.fonts().get("title"), x, y);

        hitbox = lib.display().measure("Press any key to restart", lib.fonts().get("subtitle"), 0, 0);
        x = (lib.display().width() - hitbox.width) / 2.0f;
        y = (lib.display().height() - hitbox.height) / 2.0f + 1;
        lib.display().print("Press any key to restart", lib.fonts().get("subtitle"), x, y);

        lib.display().flush();
    }
}
