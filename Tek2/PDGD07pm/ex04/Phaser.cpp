/*
** EPITECH PROJECT, 2024
** Phaser.cpp
** File description:
** Phaser.cpp
*/

#include "Phaser.hpp"
#include "Sounds.hpp"

#include <iostream>

const int Phaser::Empty = 0;

Phaser::Phaser(int maxAmmo, AmmoType type)
    : _maxAmmo(maxAmmo), _defaultType(type), _magazine(_maxAmmo, type)
{
}

void Phaser::fire()
{
    if (_magazine.size() == Phaser::Empty) {
        std::cout << "Clip empty, please reload" << std::endl;
    } else {
        AmmoType ammo = _magazine.front();
        _magazine.pop_front();

        switch (ammo) {
        case REGULAR:
            std::cout << Sounds::Regular << std::endl;
            break;
        case PLASMA:
            std::cout << Sounds::Plasma << std::endl;
            break;
        case ROCKET:
            std::cout << Sounds::Rocket << std::endl;
            break;
        }
    }
}

void Phaser::ejectClip()
{
    this->_magazine.clear();
}

void Phaser::changeType(AmmoType newType)
{
    this->_defaultType = newType;
    std::cout << "Switching ammo to type: ";

    switch (this->_defaultType) {
    case REGULAR:
        std::cout << "regular" << std::endl;
        break;
    case PLASMA:
        std::cout << "plasma" << std::endl;
        break;
    case ROCKET:
        std::cout << "rocket" << std::endl;
        break;
    }
}

void Phaser::reload()
{
    std::cout << "Reloading..." << std::endl;
    this->_magazine = std::deque(this->_maxAmmo, this->_defaultType);
}

void Phaser::addAmmo(AmmoType type)
{
    if (static_cast<int>(this->_magazine.size()) == this->_maxAmmo) {
        std::cout << "Clip full" << std::endl;
        return;
    }
    this->_magazine.push_back(type);
}

int Phaser::getCurrentAmmos() const
{
    return this->_magazine.size();
}
