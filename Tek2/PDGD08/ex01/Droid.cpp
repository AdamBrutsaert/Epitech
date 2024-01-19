/*
** EPITECH PROJECT, 2024
** Droid.cpp
** File description:
** Droid.cpp
*/

#include "Droid.hpp"

#include <algorithm>
#include <iostream>

Droid::Droid(std::string serial)
    : _id(serial), _energy(50), _attack(25), _toughness(15),
      _status(new std::string("Standing by")), _battleData(new DroidMemory())
{
    std::cout << "Droid '" << this->_id << "' Activated" << std::endl;
}

Droid::Droid(const Droid &droid)
    : _id(droid._id), _energy(droid._energy), _attack(droid._attack),
      _toughness(droid._toughness), _status(new std::string(*droid._status)),
      _battleData(new DroidMemory(*droid._battleData))
{
    std::cout << "Droid '" << this->_id << "' Activated, Memory Dumped" << std::endl;
}

Droid &Droid::operator=(const Droid &droid)
{
    this->_id = droid._id;
    this->_energy = droid._energy;
    delete this->_status;
    this->_status = new std::string(*droid._status);
    delete this->_battleData;
    this->_battleData = new DroidMemory(*droid._battleData);
    return *this;
}

Droid::~Droid()
{
    std::cout << "Droid '" << this->_id << "' Destroyed" << std::endl;
    delete this->_status;
    delete this->_battleData;
}

bool Droid::operator==(const Droid &droid) const
{
    return *this->_status == *droid._status;
}

Droid &Droid::operator<<(size_t &energy)
{
    if (this->_energy >= 100)
        return *this;

    size_t stealing = std::min(100 - this->_energy, energy);
    this->_energy += stealing;
    energy -= stealing;
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Droid& droid) {
    return os << "Droid '" << droid.getId() << "', " << *droid.getStatus() << ", " << droid.getEnergy();
}
