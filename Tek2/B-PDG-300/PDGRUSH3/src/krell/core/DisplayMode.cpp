/*
** EPITECH PROJECT, 2024
** DisplayMode.cpp
** File description:
** DisplayMode.cpp
*/

#include "krell/core/Configuration.hpp"

Krell::DisplayMode Krell::getDisplayModeFromString(const std::string &str)
{
    if (str == "ncurses")
        return Krell::DisplayMode::NCURSES;
    else if (str == "sfml")
        return Krell::DisplayMode::SFML;
    return Krell::DisplayMode::UNKNOWN;
};
