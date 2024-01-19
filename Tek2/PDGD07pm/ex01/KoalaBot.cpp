/*
** EPITECH PROJECT, 2024
** KoalaBot.cpp
** File description:
** KoalaBot.cpp
*/

#include "KoalaBot.hpp"

#include <iostream>

KoalaBot::KoalaBot(const std::string &serial) noexcept
    : _serial(serial)
{
}

void KoalaBot::informations() const noexcept
{
    std::cout << "[KoalaBot] " << this->_serial << std::endl;
    this->_arms.informations();
    this->_legs.informations();
    this->_head.informations();
}
