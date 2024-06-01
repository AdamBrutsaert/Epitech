/*
** EPITECH PROJECT, 2024
** LibrarySelection.hpp
** File description:
** LibrarySelection.hpp
*/

#pragma once

#include "arcade/ILibrary.hpp"

namespace core {
    class Core;
};

namespace core::selection {
    class LibrarySelection {
    public:
        LibrarySelection(Core& core);
        ~LibrarySelection() = default;

        void onKeyPressed(arc::ILibrary& lib, arc::KeyCode key, bool shift);
        void draw(arc::ILibrary& lib, bool selected);

    private:
        Core& _core;
        std::size_t _selected;
    };
}
