/*
** EPITECH PROJECT, 2024
** GameSelection.hpp
** File description:
** GameSelection.hpp
*/

#pragma once

#include "arcade/ILibrary.hpp"

namespace core {
    class Core;
}

namespace core::selection {
    class GameSelection {
    public:
        GameSelection(Core& core);
        ~GameSelection() = default;

        void onKeyPressed(arc::ILibrary& lib, arc::KeyCode key, bool shift);
        void draw(arc::ILibrary& lib, bool selected);
    private:
        Core& _core;
        std::size_t _selected;
    };
}
