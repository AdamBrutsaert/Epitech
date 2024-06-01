/*
** EPITECH PROJECT, 2024
** SFMLLibrary.hpp
** File description:
** SFMLLibrary.hpp
*/

#pragma once

#include "arcade/ILibrary.hpp"

#include "SFMLDisplay.hpp"
#include "SFMLTextureManager.hpp"
#include "SFMLFontManager.hpp"
#include "SFMLMusicManager.hpp"
#include "SFMLSoundManager.hpp"

class SFMLLibrary : public arc::ILibrary {
public:
    SFMLLibrary() = default;
    virtual ~SFMLLibrary() = default;

    inline virtual std::string name() const { return "SFML"; }
    inline virtual arc::IDisplay& display() { return this->_display; }
    inline virtual arc::ITextureManager& textures() { return this->_textures; }
    inline virtual arc::IFontManager& fonts() { return this->_fonts; }
    inline virtual arc::IMusicManager& musics() { return this->_musics; }
    inline virtual arc::ISoundManager& sounds() { return this->_sounds; }

private:
    SFMLDisplay _display;
    SFMLTextureManager _textures;
    SFMLFontManager _fonts;
    SFMLMusicManager _musics;
    SFMLSoundManager _sounds;
};
