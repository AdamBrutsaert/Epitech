/*
** EPITECH PROJECT, 2024
** NCursesLibrary.hpp
** File description:
** NCursesLibrary.hpp
*/

#pragma once

#include "arcade/ILibrary.hpp"

#include "NCursesDisplay.hpp"
#include "NCursesTextureManager.hpp"
#include "NCursesFontManager.hpp"
#include "NCursesMusicManager.hpp"
#include "NCursesSoundManager.hpp"

class NCursesLibrary : public arc::ILibrary {
public:
    NCursesLibrary() = default;
    virtual ~NCursesLibrary() = default;

    inline virtual std::string name() const { return "SFML"; }
    inline virtual arc::IDisplay& display() { return this->_display; }
    inline virtual arc::ITextureManager& textures() { return this->_textures; }
    inline virtual arc::IFontManager& fonts() { return this->_fonts; }
    inline virtual arc::IMusicManager& musics() { return this->_musics; }
    inline virtual arc::ISoundManager& sounds() { return this->_sounds; }

private:
    NCursesDisplay _display;
    NCursesTextureManager _textures;
    NCursesFontManager _fonts;
    NCursesMusicManager _musics;
    NCursesSoundManager _sounds;
};
