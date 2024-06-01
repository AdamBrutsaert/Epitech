/*
** EPITECH PROJECT, 2024
** UsernameSelection.hpp
** File description:
** UsernameSelection.hpp
*/

#pragma once

#include "arcade/ILibrary.hpp"

namespace core::selection {
    class UsernameSelection {
    public:
        UsernameSelection();
        ~UsernameSelection() = default;

        void onKeyPressed(arc::ILibrary& lib, arc::KeyCode key, bool shift);
        void draw(arc::ILibrary& lib, bool selected);

        inline std::string username() const { return _username; }

    private:
        std::string _username;
    };
}
