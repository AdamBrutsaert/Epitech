/*
** EPITECH PROJECT, 2024
** Library.cpp
** File description:
** Library.cpp
*/

#include "Library.hpp"

namespace sdl2 {
    Library::Library()
        : _textures(this->_display)
    {
        SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
        Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
    }

    Library::~Library()
    {
        Mix_Quit();
        SDL_Quit();
    }
}
