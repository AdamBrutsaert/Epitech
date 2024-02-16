/*
** EPITECH PROJECT, 2024
** Knight.cpp
** File description:
** Knight.cpp
*/

#include "Knight.hpp"

Knight::Knight(const std::string &name, int power)
    : Peasant(name, power)
{
    this->_tell("vows to protect the kingdom.");
}

Knight::~Knight()
{
    this->_tell("takes off his armor.");
}

int Knight::attack()
{
    if (!this->_checkHealth() || !this->_checkPower(10))
        return 0;

    this->_tell("strikes with his sword.");
    this->_power -= 10;

    return 20;
}

int Knight::special()
{
    if (!this->_checkHealth() || !this->_checkPower(30))
        return 0;

    this->_tell("impales his enemy.");
    this->_power -= 30;

    return 50;
}

void Knight::rest()
{
    if (!this->_checkHealth())
        return;

    this->_tell("eats.");
    this->_power = std::min(this->_power + 50, 100);
}
