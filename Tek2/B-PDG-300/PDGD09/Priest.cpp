/*
** EPITECH PROJECT, 2024
** Priest.cpp
** File description:
** Priest.cpp
*/

#include "Priest.hpp"

#include <algorithm>

Priest::Priest(const std::string &name, int power)
    : Peasant(name, power), Enchanter(name, power)
{
    this->_tell("enters in the order.");
}

Priest::~Priest()
{
    this->_tell("finds peace.");
}

void Priest::rest()
{
    if (!this->_checkHealth())
        return;

    this->_power = std::min(this->_power + 100, 100);
    this->_health = std::min(this->_health + 100, 100);

    this->_tell("prays.");
}
