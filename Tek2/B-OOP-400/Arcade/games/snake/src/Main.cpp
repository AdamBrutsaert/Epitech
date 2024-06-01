/*
** EPITECH PROJECT, 2024
** Main.cpp
** File description:
** Main.cpp
*/

#include "snake/Game.hpp"

#include "arcade/SharedLibraryType.hpp"

extern "C" arc::IGame *entrypoint()
{
    return new snake::Game;
}

extern "C" arc::SharedLibraryType type()
{
    return arc::SharedLibraryType::GAME;
}

extern "C" const char *name()
{
    return "Snake";
}
