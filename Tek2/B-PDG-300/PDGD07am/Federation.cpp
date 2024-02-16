/*
** EPITECH PROJECT, 2024
** Federation.cpp
** File description:
** Federation.cpp
*/

#include "Federation.hpp"

#include <iostream>

namespace Federation::Starfleet {

    Ship::Ship(int length, int width, std::string name, short maxWarp, int torpedo)
        : _length(length), _width(width), _name(name), _maxWarp(maxWarp), _core(nullptr),
          _captain(nullptr), _home(EARTH), _location(EARTH), _shield(100), _photonTorpedo(torpedo)
    {
        std::cout << "The ship USS " << this->_name << " has been finished." << std::endl
                  << "It is " << this->_length << " m in length and " << this->_width<< " m in width." << std::endl
                  << "It can go to Warp " << this->_maxWarp << "!" << std::endl;

        if (this->_photonTorpedo != 0)
            std::cout << "Weapons are set: " << this->_photonTorpedo << " torpedoes ready." << std::endl;
    }

    void Ship::setupCore(WarpSystem::Core *core)
    {
        this->_core = core;
        std::cout << "USS " << this->_name << ": The core is set." << std::endl;
    }

    void Ship::checkCore(void)
    {
        std::cout << "USS " << this->_name << ": The core is " << (this->_core->checkReactor()->isStable() ? "stable" : "unstable") << " at the time." << std::endl;
    }

    void Ship::promote(Captain *captain)
    {
        this->_captain = captain;
        std::cout << this->_captain->getName() << ": I'm glad to be the captain of the USS " << this->_name << "." << std::endl;
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

    void Ship::fire(Borg::Ship *target)
    {
        if (this->_photonTorpedo == 0) {
            std::cout << this->_name << ": No more torpedo to fire, " << this->_captain->getName() << "!" << std::endl;
            return;
        }

        this->_photonTorpedo -= 1;
        std::cout << this->_name << ": Firing on target. " << this->_photonTorpedo << " torpedoes remaining." << std::endl;
        target->setShield(target->getShield() - 50);
    }

    void Ship::fire(int torpedoes, Borg::Ship *target)
    {
        if (this->_photonTorpedo < torpedoes) {
            std::cout << this->_name << ": No enough torpedoes to fire, " << this->_captain->getName() << "!" << std::endl;
            return;
        }

        this->_photonTorpedo -= torpedoes;
        std::cout << this->_name << ": Firing on target. " << this->_photonTorpedo << " torpedoes remaining." << std::endl;
        target->setShield(target->getShield() - torpedoes * 50);
    }

    Captain::Captain(std::string name)
        : _name(name), _age(0)
    {
    }

    Ensign::Ensign(std::string name)
        : _name(name)
    {
        std::cout << "Ensign " << this->_name << ", awaiting orders." << std::endl;
    }
}

namespace Federation {
        Ship::Ship(int length, int width, std::string name)
            : _length(length), _width(width), _name(name), _maxWarp(1), _core(nullptr),
              _home(VULCAN), _location(VULCAN)
        {
            std::cout << "The independent ship " << this->_name << " just finished its construction." << std::endl
                      << "It is " << this->_length << " m in length and " << this->_width << " m in width." << std::endl;
        }

        void Ship::setupCore(WarpSystem::Core *core)
        {
            this->_core = core;
            std::cout << this->_name << ": The core is set." << std::endl;
        }

        void Ship::checkCore(void)
        {
            std::cout << this->_name << ": The core is " << (this->_core->checkReactor()->isStable() ? "stable" : "unstable") << " at the time." << std::endl;
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
}
