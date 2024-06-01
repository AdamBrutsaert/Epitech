/*
** EPITECH PROJECT, 2024
** Library.hpp
** File description:
** Library.hpp
*/

#pragma once

#include "arcade/ILibrary.hpp"

#include "Display.hpp"
#include "TextureManager.hpp"
#include "FontManager.hpp"
#include "MusicManager.hpp"
#include "SoundManager.hpp"

namespace sdl2 {
    class Library : public arc::ILibrary {
    public:
        Library();
        virtual ~Library();

        inline virtual arc::IDisplay& display() { return this->_display; }
        inline virtual arc::ITextureManager& textures() { return this->_textures; }
        inline virtual arc::IFontManager& fonts() { return this->_fonts; }
        inline virtual arc::IMusicManager& musics() { return this->_musics; }
        inline virtual arc::ISoundManager& sounds() { return this->_sounds; }

    private:
        Display _display;
        TextureManager _textures;
        FontManager _fonts;
        MusicManager _musics;
        SoundManager _sounds;
    };
}
