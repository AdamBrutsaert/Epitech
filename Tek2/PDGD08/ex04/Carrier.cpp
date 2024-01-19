/*
** EPITECH PROJECT, 2024
** Carrier.cpp
** File description:
** Carrier.cpp
*/

#include "Carrier.hpp"


Carrier::Carrier(std::string id)
    : _id(id), _energy(300), attack(100), toughness(90), _speed(0),
      _x(0), _y(0)
{
    for (size_t i = 0; i < 5; i++)
        _droids[i] = nullptr;
}

Carrier::~Carrier()
{
    for (size_t i = 0; i < 5; i++) {
        if (_droids[i] != nullptr)
            delete _droids[i];
    }
}

Carrier &Carrier::operator<<(Droid *&droid)
{
    for (size_t i = 0; i < 5; i++) {
        if (this->_droids[i] == nullptr) {
            this->_droids[i] = droid;
            droid = nullptr;
            ~(*this);
            return *this;
        }
    }

    return *this;
}

Carrier &Carrier::operator<<(size_t &energy)
{
    if (this->_energy >= 600)
        return *this;

    size_t stealing = std::min(600 - this->_energy, energy);
    this->_energy += stealing;
    energy -= stealing;
    return *this;
}

Carrier &Carrier::operator>>(Droid *&droid)
{
    for (size_t i = 0; i < 5; i++) {
        if (this->_droids[i] != nullptr) {
            droid = this->_droids[i];
            this->_droids[i] = nullptr;
            ~(*this);
            return *this;
        }
    }

    return *this;
}

size_t Carrier::getDroidsCount() const
{
    size_t count = 0;

    for (size_t i = 0; i < 5; i++) {
        if (this->_droids[i] != nullptr)
            count++;
    }

    return count;
}

Carrier &Carrier::operator~()
{
    size_t count = this->getDroidsCount();
    this->_speed = !!count * 100 - count * 10;
    return *this;
}

bool Carrier::operator()(int x, int y)
{
    if (this->_speed == 0)
        return false;

    const size_t energy = (std::abs(x) + std::abs(y)) * (10 + this->getDroidsCount());

    if (this->_energy < energy)
        return false;

    this->_energy -= energy;
    this->_x += x;
    this->_y += y;

    return true;
}

std::ostream& operator<<(std::ostream& os, const Carrier& carrier)
{
    os << "Carrier '" << carrier.getId() << "' Droid(s) on-board:" << std::endl;
    for (size_t i = 0; i < 5; i++) {
        if (carrier[i] != nullptr)
            os << "[" << i << "] : " << *carrier[i] << std::endl;
        else
            os << "[" << i << "] : Free" << std::endl;
    }
    os << "Speed : " << carrier.getSpeed() << ", Energy " << carrier.getEnergy();
    return os;
}
