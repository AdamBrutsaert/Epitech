/*
** EPITECH PROJECT, 2024
** Core.hpp
** File description:
** Core.hpp
*/

#pragma once

#include "libraries/ArcadeSharedLibrary.hpp"
#include "selection/Game.hpp"

#include <vector>

namespace core {
    class Core {
    public:
        Core();
        ~Core() = default;
        Core(const Core& other) = delete;
        Core(Core&& other) = delete;
        Core& operator=(const Core& other) = delete;
        Core& operator=(Core&& other) = delete;

        bool run(const std::string& path);

        const std::vector<ArcadeSharedLibrarySpecification>& libraries() const;
        const std::vector<ArcadeSharedLibrarySpecification>& games() const;

        void setNextLibrary(const std::string& path);
        void setNextGame(const std::string& path);

        std::string currentLibraryPath() const;
        inline const std::map<std::string, std::pair<std::string, uint64_t>>& scores() const { return _scores; }

    private:
        // Relative to the main loop
        bool _loop();
        void _handleEvents();
        void _handleGame(float deltaTime);

        // Relative to the libraries and games
        void _fetchLibrariesAndGames();

        // Relative to the libraries
        std::size_t _findLibraryIndex(const std::string& path);
        bool _switchLibrary();
        void _switchNextLibrary();
        void _switchPreviousLibrary();

        // Relative to the games
        std::size_t _findGameIndex(const std::string& path);
        bool _switchGame();
        void _switchNextGame();
        void _switchPreviousGame();

    private:
        // Loaders of library and game
        ArcadeSharedLibrary<arc::ILibrary> _library;
        ArcadeSharedLibrary<arc::IGame> _game;
        selection::Game _selection;

        // Available libraries and games
        std::vector<ArcadeSharedLibrarySpecification> _libraries;
        std::vector<ArcadeSharedLibrarySpecification> _games;

        // Index of the current library and game
        std::size_t _currentLibraryIndex;
        std::size_t _currentGameIndex;

        // Path to the next library and game
        std::optional<std::string> _nextLibrary;
        std::optional<std::string> _nextGame;

        // High scores by game
        std::map<std::string, std::pair<std::string, uint64_t>> _scores;
    };
}
