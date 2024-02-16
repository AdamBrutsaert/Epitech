/*
** EPITECH PROJECT, 2024
** Enchanter.cpp
** File description:
** Enchanter.cpp
*/

#include "Enchanter.hpp"

#include <algorithm>

Enchanter::Enchanter(const std::string &name, int power)
    : Peasant(name, power)
{
    this->_tell("learns magic from his spellbook.");
}

Enchanter::~Enchanter()
{
    this->_tell("closes his spellbook.");
}

int Enchanter::attack()
{
    if (!this->_checkHealth())
        return 0;

    this->_tell("doesn't know how to fight.");

    return 0;
}

int Enchanter::special()
{
    if (!this->_checkHealth() || !this->_checkPower(50))
        return 0;

    this->_power -= 50;
    this->_tell("casts a fireball.");

    return 99;
}

void Enchanter::rest()
{
    if (!this->_checkHealth())
        return;

    this->_power = std::min(this->_power + 100, 100);
    this->_tell("meditates.");
}
