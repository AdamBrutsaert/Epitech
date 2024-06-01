/*
** EPITECH PROJECT, 2024
** LibrarySelection.cpp
** File description:
** LibrarySelection.cpp
*/

#include "selection/LibrarySelection.hpp"
#include "Core.hpp"

#include <cmath>

namespace core::selection {
    LibrarySelection::LibrarySelection(Core& core)
        : _core(core), _selected{0}
    {
    }

    void LibrarySelection::onKeyPressed([[maybe_unused]] arc::ILibrary& lib, arc::KeyCode key, bool shift)
    {
        if (shift) return;

        if (key == arc::KeyCode::DOWN) {
            this->_selected = (this->_selected + 1) % this->_core.libraries().size();
        } else if (key == arc::KeyCode::UP) {
            this->_selected = (this->_selected + this->_core.libraries().size() - 1) % this->_core.libraries().size();
        } else if (key == arc::KeyCode::ENTER && this->_selected < this->_core.libraries().size()) {
            this->_core.setNextLibrary(this->_core.libraries()[this->_selected].path);
        }
    }

    void LibrarySelection::draw(arc::ILibrary& lib, bool selected)
    {
        // Libs are drawn at the bottom right corner
        std::size_t x = std::ceil(lib.display().width() / 2.0f);
        std::size_t y = std::ceil(lib.display().height() / 2.0f);
        std::size_t width = std::floor(lib.display().width() / 2.0f);

        // If for some reason we overextended
        if (this->_selected >= this->_core.libraries().size())
            this->_selected = 0;

        // Draw the title
        auto titleHitbox = lib.display().measure("Libraries", lib.fonts().get("regular"), 0, 0);
        auto titleX = x + (width - titleHitbox.width) / 2.0f;
        auto titleY = y + 1;

        if (selected) {
            lib.display().print("Libraries", lib.fonts().get("focus"), titleX, titleY);
        } else {
            lib.display().print("Libraries", lib.fonts().get("regular"), titleX, titleY);
        }

        // Drawing the list of all the libraries
        for (std::size_t i = 0; i < this->_core.libraries().size(); i++) {
            auto& library = this->_core.libraries()[i];

            auto libraryHitbox = lib.display().measure(library.name, lib.fonts().get("regular"), 0, 0);
            auto libraryX = x + (width - libraryHitbox.width) / 2.0f;
            auto libraryY = y + 3 + i;

            if (i == this->_selected) {
                lib.display().print(library.name, lib.fonts().get("focus"), libraryX, libraryY);
            } else if (library.path == this->_core.currentLibraryPath()) {
                lib.display().print(library.name, lib.fonts().get("selected"), libraryX, libraryY);
            } else {
                lib.display().print(library.name, lib.fonts().get("regular"), libraryX, libraryY);
            }
        }
    }
}
