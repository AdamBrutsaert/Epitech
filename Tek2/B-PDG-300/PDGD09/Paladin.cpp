/*
** EPITECH PROJECT, 2024
** Paladin.cpp
** File description:
** Paladin.cpp
*/

#include "Paladin.hpp"

Paladin::Paladin(const std::string &name, int power)
    : Peasant(name, power), Knight(name, power), Priest(name, power)
{
    Knight::_tell("fights for the light.");
}

Paladin::~Paladin()
{
    Knight::_tell("is blessed.");
}

int Paladin::attack()
{
    return Knight::attack();
}

int Paladin::special()
{
    return Enchanter::special();
}

void Paladin::rest()
{
    Priest::rest();
}
