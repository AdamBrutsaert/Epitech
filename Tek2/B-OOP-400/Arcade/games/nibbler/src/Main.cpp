/*
** EPITECH PROJECT, 2024
** Main.cpp
** File description:
** Main.cpp
*/

#include "nibbler/Game.hpp"

#include "arcade/SharedLibraryType.hpp"

extern "C" arc::IGame *entrypoint()
{
    return new nibbler::Game;
}

extern "C" arc::SharedLibraryType type()
{
    return arc::SharedLibraryType::GAME;
}

extern "C" const char *name()
{
    return "Nibbler";
}
