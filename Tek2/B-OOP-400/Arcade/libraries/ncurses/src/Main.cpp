/*
** EPITECH PROJECT, 2024
** Main.cpp
** File description:
** Main.cpp
*/

#include "NCursesLibrary.hpp"

#include "arcade/SharedLibraryType.hpp"

extern "C" arc::ILibrary *entrypoint()
{
    return new NCursesLibrary;
}

extern "C" arc::SharedLibraryType type()
{
    return arc::SharedLibraryType::LIBRARY;
}

extern "C" const char *name()
{
    return "NCurses";
}
