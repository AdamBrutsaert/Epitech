/*
** EPITECH PROJECT, 2024
** Core.cpp
** File description:
** Core.cpp
*/

#include "Core.hpp"

#include <chrono>
#include <filesystem>

namespace core {
    Core::Core()
        : _selection(*this), _currentLibraryIndex(0), _currentGameIndex(0)
    {
        this->_fetchLibrariesAndGames();
    }

    const std::vector<ArcadeSharedLibrarySpecification>& Core::libraries() const
    {
        return this->_libraries;
    }

    const std::vector<ArcadeSharedLibrarySpecification>& Core::games() const
    {
        return this->_games;
    }

    std::string Core::currentLibraryPath() const
    {
        return this->_library.path();
    }

    bool Core::run(const std::string& path)
    {
        this->_nextLibrary = path;
        if (!this->_switchLibrary())
            return false;

        this->_selection.initialize(*this->_library.instance());
        return this->_loop();
    }

    bool Core::_loop()
    {
        auto timeFrameStarted = std::chrono::high_resolution_clock::now();

        while (this->_library.instance()->display().opened()) {
            // Compute elapsed time since last frame
            auto timeFrameEnded = std::chrono::high_resolution_clock::now();
            auto frameDuration = std::chrono::duration_cast<std::chrono::duration<float, std::milli>>(timeFrameEnded - timeFrameStarted).count() / 1000.0;

            // Switch library or game if n_scoreseeded
            if (this->_nextLibrary.has_value() && !this->_switchLibrary())
                return false;
            if (this->_nextGame.has_value() && !this->_switchGame())
                return false;

            timeFrameStarted = std::chrono::high_resolution_clock::now();

            // Update & Render
            this->_library.instance()->display().update(frameDuration);
            this->_handleEvents();
            this->_handleGame(frameDuration);
        }

        return true;
    }

    void Core::_handleEvents()
    {
        arc::Event event;
        arc::IGame& game = this->_game.instance() == nullptr ? this->_selection : *this->_game.instance();

        while (this->_library.instance()->display().pollEvent(event)) {
            if (event.type == arc::EventType::KEY_PRESSED && event.key.shift) {
                if (event.key.code == arc::KeyCode::S)
                    this->_switchNextLibrary();
                if (event.key.code == arc::KeyCode::Z)
                    this->_switchPreviousLibrary();
                if (event.key.code == arc::KeyCode::D)
                    this->_switchNextGame();
                if (event.key.code == arc::KeyCode::Q)
                    this->_switchPreviousGame();
                if (event.key.code == arc::KeyCode::E)
                    this->_library.instance()->display().close();
                if (event.key.code == arc::KeyCode::M)
                    this->_nextGame = "";
                if (event.key.code == arc::KeyCode::R && this->_game.instance() != nullptr)
                    this->_nextGame = this->_games[this->_currentGameIndex].path;
            }

            if (event.type == arc::EventType::KEY_PRESSED && event.key.code == arc::KeyCode::ESCAPE)
                this->_nextGame = "";

            // Dispatch events to the game
            if (event.type == arc::EventType::KEY_PRESSED)
                game.onKeyPressed(*this->_library.instance(), event.key.code, event.key.shift);
            if (event.type == arc::EventType::MOUSE_BUTTON_PRESSED)
                game.onMouseButtonPressed(*this->_library.instance(), event.mouse.button, event.mouse.x, event.mouse.y);
        }
    }

    void Core::_handleGame(float deltaTime)
    {
        arc::IGame& game = this->_game.instance() == nullptr ? this->_selection : *this->_game.instance();

        // Save the score of the current game
        if (this->_game.instance() != nullptr) {
            auto game = this->_games[this->_currentGameIndex].name;
            auto score = this->_game.instance()->score();
            auto username = this->_selection.username();

            if (!this->_scores.contains(game) || score > this->_scores[game].second)
                this->_scores[game] = {username, score};
        }

        game.update(*this->_library.instance(), deltaTime);
        game.draw(*this->_library.instance());
    }

    void Core::_fetchLibrariesAndGames()
    {
        this->_libraries.clear();
        this->_games.clear();

        try {
            for (const auto& entry : std::filesystem::directory_iterator("lib")) {
                if (entry.path().extension() == ".so") {
                    auto spec = ArcadeSharedLibrary<void>(entry.path().string()).specification();

                    if (spec.type == arc::SharedLibraryType::LIBRARY)
                        this->_libraries.push_back(std::move(spec));
                    else if (spec.type == arc::SharedLibraryType::GAME)
                        this->_games.push_back(std::move(spec));
                }
            }
        } catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }
    }

    std::size_t Core::_findLibraryIndex(const std::string& path)
    {
        for (std::size_t i = 0; i < this->_libraries.size(); i++) {
            if (this->_libraries[i].path == path)
                return i;
        }
        return 0;
    }

    std::size_t Core::_findGameIndex(const std::string& path)
    {
        for (std::size_t i = 0; i < this->_games.size(); i++) {
            if (this->_games[i].path == path)
                return i;
        }
        return 0;
    }

    bool Core::_switchLibrary()
    {
        if (!this->_nextLibrary.has_value())
            return false;

        auto dump = this->_library.dump();

        if (!this->_library.open(this->_nextLibrary.value())) {
            this->_nextLibrary.reset();
            return false;
        }

        this->_nextLibrary.reset();

        if (this->_library.type() != arc::SharedLibraryType::LIBRARY) {
            this->_library.close();
            return false;
        }

        if (this->_library.instance() == nullptr)
            return false;

        this->_library.restore(dump);

        this->_currentLibraryIndex = this->_findLibraryIndex(this->_library.path());
        return true;
    }

    void Core::_switchNextLibrary()
    {
        this->_nextLibrary = this->_libraries[(this->_currentLibraryIndex + 1) % this->_libraries.size()].path;
    }

    void Core::_switchPreviousLibrary()
    {
        this->_nextLibrary = this->_libraries[(this->_currentLibraryIndex + this->_libraries.size() - 1) % this->_libraries.size()].path;
    }

    bool Core::_switchGame()
    {
        if (!this->_nextGame.has_value())
            return false;

        if (this->_nextGame.value() == "") {
            this->_nextGame.reset();
            this->_game.close();
            this->_selection.initialize(*this->_library.instance());
            return true;
        }

        if (!this->_game.open(this->_nextGame.value())) {
            this->_nextGame.reset();
            return false;
        }

        this->_nextGame.reset();

        if (this->_game.instance() == nullptr)
            return false;

        this->_game.instance()->initialize(*this->_library.instance());
        this->_currentGameIndex = this->_findGameIndex(this->_game.path());
        return true;
    }

    void Core::_switchNextGame()
    {
        this->_nextGame = this->_games[(this->_currentGameIndex + 1) % this->_games.size()].path;
    }

    void Core::_switchPreviousGame()
    {
        this->_nextGame = this->_games[(this->_currentGameIndex + this->_games.size() - 1) % this->_games.size()].path;
    }

    void Core::setNextLibrary(const std::string& path)
    {
        this->_nextLibrary = path;
    }

    void Core::setNextGame(const std::string& path)
    {
        this->_nextGame = path;
    }
}
