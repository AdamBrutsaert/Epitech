/*
** EPITECH PROJECT, 2024
** Borg.cpp
** File description:
** Borg.cpp
*/

#include "Borg.hpp"
#include "Federation.hpp"

#include <iostream>

namespace Borg {

    Ship::Ship(int weaponFrequency, short repair)
        : _side(300), _maxWarp(9), _core(nullptr), _home(UNICOMPLEX), _location(UNICOMPLEX),
          _shield(100), _weaponFrequency(weaponFrequency), _repair(repair)
    {
        std::cout << "We are the Borgs. Lower your shields and surrender yourselves unconditionally." << std::endl;
        std::cout << "Your biological characteristics and technologies will be assimilated." << std::endl;
        std::cout << "Resistance is futile." << std::endl;
    }

    void Ship::setupCore(WarpSystem::Core *core)
    {
        this->_core = core;
    }

    void Ship::checkCore(void)
    {
        std::cout << (this->_core->checkReactor()->isStable() ? "Everything is in order." : "Critical failure imminent.") << std::endl;
    }

    bool Ship::move(int warp, Destination d)
    {
        if (warp <= _maxWarp && d != _location && _core->checkReactor()->isStable()) {
            _location = d;
            return true;
        }
        return false;
    }

    bool Ship::move(int warp)
    {
        if (warp <= _maxWarp && _core->checkReactor()->isStable()) {
            _location = _home;
            return true;
        }
        return false;
    }

    bool Ship::move(Destination d)
    {
        if (d != _location && _core->checkReactor()->isStable()) {
            _location = d;
            return true;
        }
        return false;
    }

    bool Ship::move()
    {
        if (_core->checkReactor()->isStable()) {
            _location = _home;
            return true;
        }
        return false;
    }

    void Ship::fire(Federation::Starfleet::Ship *target)
    {
        std::cout << "Firing on target with " << this->_weaponFrequency << "GW frequency." << std::endl;
        target->setShield(target->getShield() - this->_weaponFrequency);
    }

    void Ship::fire(Federation::Ship *target)
    {
        std::cout << "Firing on target with " << this->_weaponFrequency << "GW frequency." << std::endl;
        target->getCore()->checkReactor()->setStability(false);
    }

    void Ship::repair()
    {
        if (_repair > 0) {
            _repair -= 1;
            _shield = 100;
            std::cout << "Begin shield re-initialisation... Done. Awaiting further instructions." << std::endl;
        } else {
            std::cout << "Energy cells depleted, shield weakening." << std::endl;
        }
    }
}
