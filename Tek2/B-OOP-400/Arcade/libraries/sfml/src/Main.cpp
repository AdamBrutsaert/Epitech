/*
** EPITECH PROJECT, 2024
** Main.cpp
** File description:
** Main.cpp
*/

#include "SFMLLibrary.hpp"

#include "arcade/SharedLibraryType.hpp"

extern "C" arc::ILibrary *entrypoint()
{
    return new SFMLLibrary;
}

extern "C" arc::SharedLibraryType type()
{
    return arc::SharedLibraryType::LIBRARY;
}

extern "C" const char *name()
{
    return "SFML";
}
