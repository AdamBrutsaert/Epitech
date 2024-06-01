/*
** EPITECH PROJECT, 2024
** ScoreSelection.cpp
** File description:
** ScoreSelection.cpp
*/

#include "selection/ScoreSelection.hpp"
#include "Core.hpp"

#include <cmath>

namespace core::selection {
    ScoreSelection::ScoreSelection(Core &core)
        : _core(core), _selected(0)
    {
    }

    void ScoreSelection::onKeyPressed([[maybe_unused]] arc::ILibrary &lib, arc::KeyCode key, bool shift)
    {
        if (shift) return;

        if (key == arc::KeyCode::RIGHT) {
            this->_selected = (this->_selected + 1) % this->_core.games().size();
        } else if (key == arc::KeyCode::LEFT) {
            this->_selected = (this->_selected + this->_core.games().size() - 1) % this->_core.games().size();
        }
    }

    void ScoreSelection::draw(arc::ILibrary &lib, bool selected)
    {
        // Libs are drawn at the top right corner
        std::size_t x = std::ceil(lib.display().width() / 2.0f);
        std::size_t width = std::floor(lib.display().width() / 2.0f);
        std::size_t height = std::floor(lib.display().height() / 2.0f);

        // Draw the title
        auto titleHitbox = lib.display().measure("Scores", lib.fonts().get("regular"), 0, 0);
        auto titleX = x + (width - titleHitbox.width) / 2.0f;
        auto titleY = 1;

        if (selected) {
            lib.display().print("Scores", lib.fonts().get("focus"), titleX, titleY);
        } else {
            lib.display().print("Scores", lib.fonts().get("regular"), titleX, titleY);
        }

        // If we over extended
        if (this->_selected >= this->_core.games().size())
            this->_selected = 0;

        // If there are no games, stop
        if (this->_core.games().empty())
            return;

        auto game = this->_core.games()[this->_selected].name;

        titleHitbox = lib.display().measure(game, lib.fonts().get("regular"), 0, 0);
        titleX = x + (width - titleHitbox.width) / 2.0f;
        titleY = (height - titleHitbox.height) / 2.0f - 1;
        lib.display().print(game, lib.fonts().get("regular"), titleX, titleY);

        // If there are no scores, stop
        if (this->_core.scores().find(game) == this->_core.scores().end())
            return;

        auto score = this->_core.scores().at(game);

        auto text = score.first;
        titleHitbox = lib.display().measure(text, lib.fonts().get("regular"), 0, 0);
        titleX = x + (width - titleHitbox.width) / 2.0f;
        titleY = (height - titleHitbox.height) / 2.0f + 1;
        lib.display().print(text, lib.fonts().get("regular"), titleX, titleY);

        text = std::to_string(score.second);
        titleHitbox = lib.display().measure(text, lib.fonts().get("regular"), 0, 0);
        titleX = x + (width - titleHitbox.width) / 2.0f;
        titleY = (height - titleHitbox.height) / 2.0f + 2;
        lib.display().print(text, lib.fonts().get("regular"), titleX, titleY);
    }
}
