/*
** EPITECH PROJECT, 2024
** ScoreSelection.hpp
** File description:
** ScoreSelection.hpp
*/

#pragma once

#include "arcade/ILibrary.hpp"

namespace core {
    class Core;
}

namespace core::selection {
    class ScoreSelection {
    public:
        ScoreSelection(Core& core);
        ~ScoreSelection() = default;

        void onKeyPressed(arc::ILibrary& lib, arc::KeyCode key, bool shift);
        void draw(arc::ILibrary& lib, bool selected);

    private:
        Core& _core;
        std::size_t _selected;
    };
}
