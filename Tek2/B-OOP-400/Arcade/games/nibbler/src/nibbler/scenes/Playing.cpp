/*
** EPITECH PROJECT, 2024
** Playing.cpp
** File description:
** Playing.cpp
*/

#include "nibbler/scenes/Playing.hpp"
#include "nibbler/scenes/GameOver.hpp"
#include "nibbler/scenes/Win.hpp"

namespace nibbler::scenes {
    Playing::Playing(uint64_t& score, utils::SceneManager& sceneManager)
        : _score(score), _sceneManager(sceneManager),
          _snake(this->_map.width(), this->_map.height()), _background(this->_map.width(), this->_map.height()),
          _gameCooldown(0), _snakeCooldown(0), _appleCooldown(0),
          _deadCooldown(0), _deadSoundPlayed(false)
    {
        this->_score = 0;
    }

    void Playing::initialize([[maybe_unused]] arc::ILibrary& lib)
    {
        // Random seed
        srand(time(nullptr));

        // Display
        lib.display().setTitle("Nibbler - Playing");
        lib.display().setFramerate(60);
        lib.display().setTileSize(32);
        lib.display().setWidth(std::max(this->_map.width(), 1u));
        lib.display().setHeight(std::max(this->_map.height(), 1u));

        // Load resources
        this->_loadBackground(lib);
        this->_loadApple(lib);
        this->_loadSnake(lib);
        this->_loadSounds(lib);
        this->_loadMap(lib);
    
        // Spawn apple
        this->_spawnApple();

        lib.musics().play("nibbler-theme", 30.0f);
    }

    void Playing::_loadBackground(arc::ILibrary& lib)
    {
        arc::TextureSpecification texture;

        texture.textual = {' ', arc::Color{0, 0, 0, 0}};
        texture.graphical = arc::TextureImage{
            "assets/nibbler/images/background.png",
            arc::URect{16u, 16u, 16u, 16u}
        };
        lib.textures().load("grass", texture);

        texture.graphical = arc::TextureImage{
            "assets/nibbler/images/background.png",
            arc::URect{0u, 5u * 16u, 16u, 16u}
        };
        lib.textures().load("herb1", texture);

        texture.graphical = arc::TextureImage{
            "assets/nibbler/images/background.png",
            arc::URect{1 * 16u, 5u * 16u, 16u, 16u}
        };
        lib.textures().load("herb2", texture);

        texture.graphical = arc::TextureImage{
            "assets/nibbler/images/background.png",
            arc::URect{2 * 16u, 5u * 16u, 16u, 16u}
        };
        lib.textures().load("herb3", texture);
    }

    void Playing::_loadApple(arc::ILibrary& lib)
    {
        arc::TextureSpecification texture;

        texture.textual = {'@', arc::Color{255, 0, 0, 255}};
        texture.graphical = arc::TextureImage{
            "assets/nibbler/images/spritesheet.png",
            arc::URect{0, 196, 64, 64}
        };
        lib.textures().load("apple", texture);
    }

    void Playing::_loadSnake(arc::ILibrary& lib)
    {
        arc::TextureSpecification texture;

        // Head
        texture.textual = {'O', arc::Color{0, 255, 0, 255}};
        texture.graphical = arc::TextureImage{
            "assets/nibbler/images/spritesheet.png",
            arc::URect{192, 0, 64, 64}
        };
        lib.textures().load("head_top", texture);

        texture.graphical = arc::TextureImage{
            "assets/nibbler/images/spritesheet.png",
            arc::URect{256, 0, 64, 64}
        };
        lib.textures().load("head_right", texture);

        texture.graphical = arc::TextureImage{
            "assets/nibbler/images/spritesheet.png",
            arc::URect{192, 64, 64, 64}
        };
        lib.textures().load("head_left", texture);

        texture.graphical = arc::TextureImage{
            "assets/nibbler/images/spritesheet.png",
            arc::URect{256, 64, 64, 64}
        };
        lib.textures().load("head_bottom", texture);

        // Tail
        texture.textual = {'#', arc::Color{0, 255, 0, 255}};
        texture.graphical = arc::TextureImage{
            "assets/nibbler/images/spritesheet.png",
            arc::URect{192, 128, 64, 64}
        };
        lib.textures().load("tail_top", texture);

        texture.graphical = arc::TextureImage{
            "assets/nibbler/images/spritesheet.png",
            arc::URect{256, 128, 64, 64}
        };
        lib.textures().load("tail_right", texture);

        texture.graphical = arc::TextureImage{
            "assets/nibbler/images/spritesheet.png",
            arc::URect{192, 192, 64, 64}
        };
        lib.textures().load("tail_left", texture);

        texture.graphical = arc::TextureImage{
            "assets/nibbler/images/spritesheet.png",
            arc::URect{256, 192, 64, 64}
        };
        lib.textures().load("tail_bottom", texture);

        // Body
        texture.graphical = arc::TextureImage{
            "assets/nibbler/images/spritesheet.png",
            arc::URect{0, 0, 64, 64}
        };
        lib.textures().load("body_topleft", texture);

        texture.graphical = arc::TextureImage{
            "assets/nibbler/images/spritesheet.png",
            arc::URect{64, 0, 64, 64}
        };
        lib.textures().load("body_top", texture);

        texture.graphical = arc::TextureImage{
            "assets/nibbler/images/spritesheet.png",
            arc::URect{128, 0, 64, 64}
        };
        lib.textures().load("body_topright", texture);

        texture.graphical = arc::TextureImage{
            "assets/nibbler/images/spritesheet.png",
            arc::URect{0, 64, 64, 64}
        };
        lib.textures().load("body_left", texture);

        texture.graphical = arc::TextureImage{
            "assets/nibbler/images/spritesheet.png",
            arc::URect{128, 64, 64, 64}
        };
        lib.textures().load("body_right", texture);

        texture.graphical = arc::TextureImage{
            "assets/nibbler/images/spritesheet.png",
            arc::URect{128, 128, 64, 64}
        };
        lib.textures().load("body_bottomright", texture);
    }

    void Playing::_loadSounds(arc::ILibrary& lib)
    {
        arc::SoundSpecification sound;
        sound.path = "assets/nibbler/sounds/burp.wav";
        lib.sounds().load("burp", sound);

        sound.path = "assets/nibbler/sounds/oof.wav";
        lib.sounds().load("oof", sound);

        sound.path = "assets/nibbler/sounds/victory.wav";
        lib.sounds().load("victory", sound);

        arc::MusicSpecification music;
        music.path = "assets/nibbler/sounds/nibbler_theme.wav";
        music.loop = true;
        music.isPlaying = false;
        lib.musics().load("nibbler-theme", music);
    }

    void Playing::_loadMap(arc::ILibrary& lib)
    {
        arc::TextureSpecification texture;

        texture.textual = {'v', arc::Color{255, 255, 255, 255}};
        texture.graphical = arc::TextureImage{
            "assets/nibbler/images/bush.png",
            arc::URect{0, 0, 16, 16}
        };
        lib.textures().load("wall", texture);
    }

    void Playing::onKeyPressed([[maybe_unused]] arc::ILibrary& lib, arc::KeyCode key, bool shift)
    {
        if (shift) return;

        switch (key) {
        case arc::KeyCode::UP:
            this->_snake.turn(entities::Direction::UP);
            break;
        case arc::KeyCode::DOWN:
            this->_snake.turn(entities::Direction::DOWN);
            break;
        case arc::KeyCode::LEFT:
            this->_snake.turn(entities::Direction::LEFT);
            break;
        case arc::KeyCode::RIGHT:
            this->_snake.turn(entities::Direction::RIGHT);
            break;
        default:
            break;
        }
    }

    void Playing::onMouseButtonPressed(arc::ILibrary &lib, arc::MouseButton button, int32_t x, int32_t y)
    {
        (void)lib;
        (void)button;
        (void)x;
        (void)y;
    }

    void Playing::update([[maybe_unused]] arc::ILibrary &lib, float deltaTime)
    {
        if (this->_hasWon()) {
            lib.musics().stop("nibbler-theme");
            this->_deadCooldown += deltaTime;
            if (!this->_deadSoundPlayed) {
                lib.sounds().play("victory", 50);
                this->_deadSoundPlayed = true;
            }
            if (this->_deadCooldown >= 1)
                this->_sceneManager.switchScene(std::make_shared<Win>(this->_score, this->_sceneManager));
            return;
        }

        if (this->_snake.dead()) {
            lib.musics().stop("nibbler-theme");
            this->_deadCooldown += deltaTime;
            if (!this->_deadSoundPlayed) {
                lib.sounds().play("oof", 50);
                this->_deadSoundPlayed = true;
            }
            if (this->_deadCooldown >= 1)
                this->_sceneManager.switchScene(std::make_shared<GameOver>(this->_score, this->_sceneManager));
            return;
        }

        this->_snakeCooldown += deltaTime;
        this->_appleCooldown += deltaTime;
        this->_gameCooldown += deltaTime;

        if (this->_gameCooldown >= 200) {
            this->_snake.kill();
            return;
        }

        while (this->_snakeCooldown >= 0.1) {
            this->_snake.move(this->_map);
            this->_snakeCooldown -= 0.1;
        }

        for (auto it = this->_apples.begin(); it != this->_apples.end();) {
            if (this->_snake.collides(it->x(), it->y())) {
                this->_score += 100;
                this->_snake.grow();
                lib.sounds().play("burp", 50);
                it = this->_apples.erase(it);

                if (this->_apples.size() == 0)
                    this->_spawnApple();

            } else {
                it++;
            }
        }

        while (this->_appleCooldown >= 5) {
            this->_appleCooldown -= 5;
            this->_score += 5;
            this->_spawnApple();
        }
    }

    void Playing::draw(arc::ILibrary &lib)
    {
        lib.display().clear(arc::Color{0, 0, 0, 255});
        this->_background.draw(lib);
        this->_map.draw(lib);
        for (auto& apple : this->_apples)
            apple.draw(lib);
        this->_snake.draw(lib);
        lib.display().flush();
    }

    void Playing::_spawnApple()
    {
        auto availabe = this->_snake.available();

        for (auto it = availabe.begin(); it != availabe.end();) {
            if (this->_map.get(it->x, it->y) == entities::Tile::WALL) {
                it = availabe.erase(it);
            } else {
                it++;
            }
        }

        if (availabe.size() == 0) return;

        auto pos = availabe[rand() % availabe.size()];
        this->_apples.emplace_back(pos.x, pos.y);
    }

    bool Playing::_hasWon()
    {
        auto availabe = this->_snake.available();

        for (auto it = availabe.begin(); it != availabe.end();) {
            if (this->_map.get(it->x, it->y) == entities::Tile::WALL) {
                it = availabe.erase(it);
            } else {
                it++;
            }
        }

        return availabe.size() == 0;
    }
}
