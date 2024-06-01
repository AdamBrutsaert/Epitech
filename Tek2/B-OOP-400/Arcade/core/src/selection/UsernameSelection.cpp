/*
** EPITECH PROJECT, 2024
** UsernameSelection.cpp
** File description:
** UsernameSelection.cpp
*/

#include "selection/UsernameSelection.hpp"

#include <cmath>

namespace core::selection {
    UsernameSelection::UsernameSelection()
        : _username{"UNKNOWN"}
    {
    }

    void UsernameSelection::onKeyPressed([[maybe_unused]] arc::ILibrary& lib, arc::KeyCode key, bool shift)
    {
        if (shift)
            return;

        if (key == arc::KeyCode::DELETE && !this->_username.empty())
            this->_username.pop_back();

        if (this->_username.size() >= 15)
            return;

        if (key == arc::KeyCode::SPACE)
            this->_username.push_back(' ');

        if (key >= arc::KeyCode::A && key <= arc::KeyCode::Z)
            this->_username.push_back('A' + static_cast<int32_t>(key) - static_cast<int32_t>(arc::KeyCode::A));
    }

    void UsernameSelection::draw(arc::ILibrary& lib, bool selected)
    {
        auto width = std::ceil(lib.display().width() / 2.0);
        auto height = std::ceil(lib.display().height() / 2.0);

        // Draw the title
        auto titleHitbox = lib.display().measure("Username", lib.fonts().get("regular"), 0, 0);
        auto titleX = (width - titleHitbox.width) / 2.0f;
        auto titleY = 1;

        if (selected) {
            lib.display().print("Username", lib.fonts().get("focus"), titleX, titleY);
        } else {
            lib.display().print("Username", lib.fonts().get("regular"), titleX, titleY);
        }

        // Draw the username
        auto usernameHitbox = lib.display().measure(this->_username, lib.fonts().get("regular"), 0, 0);
        auto usernameX = (width - usernameHitbox.width) / 2.0f;
        auto usernameY = (height - usernameHitbox.height) / 2.0f;
        lib.display().print(this->_username, lib.fonts().get("regular"), usernameX, usernameY);
    }
}
