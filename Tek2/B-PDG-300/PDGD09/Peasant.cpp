/*
** EPITECH PROJECT, 2024
** Peasant.cpp
** File description:
** Peasant.cpp
*/

#include "Peasant.hpp"

#include <iostream>
#include <algorithm>

Peasant::Peasant(const std::string &name, int power)
    : _name(name), _power(std::min(power, 100)), _health(100)
{
    this->_tell("goes for an adventure.");
}

Peasant::~Peasant()
{
    this->_tell("is back to his crops.");
}

void Peasant::_tell(const std::string &message)
{
    std::cout << this->_name << " " << message << std::endl;
}

bool Peasant::_checkHealth()
{
    if (this->_health == 0) {
        this->_tell("is out of combat.");
        return false;
    }
    return true;
}

bool Peasant::_checkPower(int minPower)
{
    if (this->_power < minPower) {
        this->_tell("is out of power.");
        return false;
    }
    return true;
}

int Peasant::attack()
{
    if (!this->_checkHealth() || !this->_checkPower(10))
        return 0;

    this->_power -= 10;
    this->_tell("tosses a stone.");

    return 5;
}

int Peasant::special()
{
    if (!this->_checkHealth())
        return 0;

    this->_tell("doesn't know any special move.");

    return 0;
}

void Peasant::rest()
{
    if (!this->_checkHealth())
        return;

    this->_power = std::min(this->_power + 30, 100);
    this->_tell("takes a nap.");
}

void Peasant::damage(int damage)
{
    this->_health = std::max(this->_health - damage, 0);

    if (this->_checkHealth())
        this->_tell("takes " + std::to_string(damage) + " damage.");
}

void Peasant::drink(const IPotion &potion)
{
    this->_tell("drinks a mysterious potion.");
    potion.use(this->_health, this->_power);
}

void Peasant::drink(const HealthPotion &potion)
{
    this->_tell("feels rejuvenated.");
    potion.use(this->_health, this->_power);
}

void Peasant::drink(const PowerPotion &potion)
{
    std::cout << this->_name << "'s power is restored." << std::endl;
    potion.use(this->_health, this->_power);
}

void Peasant::drink(const PoisonPotion &potion)
{
    this->_tell("has been poisoned.");
    potion.use(this->_health, this->_power);
}
