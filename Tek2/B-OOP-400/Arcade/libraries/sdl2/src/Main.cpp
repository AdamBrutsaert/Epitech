/*
** EPITECH PROJECT, 2024
** Main.cpp
** File description:
** Main.cpp
*/

#include "Library.hpp"

#include "arcade/SharedLibraryType.hpp"

extern "C" arc::ILibrary *entrypoint()
{
    return new sdl2::Library();
}

extern "C" arc::SharedLibraryType type()
{
    return arc::SharedLibraryType::LIBRARY;
}

extern "C" const char *name()
{
    return "SDL2";
}
