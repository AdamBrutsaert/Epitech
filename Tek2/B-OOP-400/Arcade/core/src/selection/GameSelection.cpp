/*
** EPITECH PROJECT, 2024
** GameSelection.cpp
** File description:
** GameSelection.cpp
*/

#include "selection/GameSelection.hpp"
#include "Core.hpp"

#include <cmath>

namespace core::selection {
    GameSelection::GameSelection(Core& core)
        : _core(core), _selected{0}
    {
    }

    void GameSelection::onKeyPressed([[maybe_unused]] arc::ILibrary& lib, arc::KeyCode key, bool shift)
    {
        if (shift) return;

        if (key == arc::KeyCode::DOWN) {
            this->_selected = (this->_selected + 1) % this->_core.games().size();
        } else if (key == arc::KeyCode::UP) {
            this->_selected = (this->_selected + this->_core.games().size() - 1) % this->_core.games().size();
        } else if (key == arc::KeyCode::ENTER && this->_selected < this->_core.games().size()) {
            this->_core.setNextGame(this->_core.games()[this->_selected].path);
        }
    }

    void GameSelection::draw(arc::ILibrary& lib, bool selected)
    {
        // Games are drawn at the bottom left corner
        std::size_t y = std::ceil(lib.display().height() / 2.0f);
        std::size_t width = std::floor(lib.display().width() / 2.0f);

        // If for some reason we overextended
        if (this->_selected >= this->_core.games().size())
            this->_selected = 0;

        // Draw the title
        auto titleHitbox = lib.display().measure("Games", lib.fonts().get("regular"), 0, 0);
        auto titleX = (width - titleHitbox.width) / 2.0f;
        auto titleY = y + 1;

        if (selected) {
            lib.display().print("Games", lib.fonts().get("focus"), titleX, titleY);
        } else {
            lib.display().print("Games", lib.fonts().get("regular"), titleX, titleY);
        }

        // Drawing the list of all the games
        for (std::size_t i = 0; i < this->_core.games().size(); i++) {
            auto& library = this->_core.games()[i];

            auto libraryHitbox = lib.display().measure(library.name, lib.fonts().get("regular"), 0, 0);
            auto libraryX = (width - libraryHitbox.width) / 2.0f;
            auto libraryY = y + 3 + i;

            if (i == this->_selected) {
                lib.display().print(library.name, lib.fonts().get("focus"), libraryX, libraryY);
            } else {
                lib.display().print(library.name, lib.fonts().get("regular"), libraryX, libraryY);
            }
        }
    }
}
