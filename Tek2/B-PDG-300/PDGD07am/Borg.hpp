/*
** EPITECH PROJECT, 2024
** Borg.hpp
** File description:
** Borg.hpp
*/

#pragma once

#include "WarpSystem.hpp"
#include "Destination.hpp"

namespace Federation::Starfleet {
    class Ship;
}

namespace Federation {
    class Ship;
}

namespace Borg {
    class Ship {
    public:
        Ship(int weaponFrequency = 20, short repair = 3);
        ~Ship() = default;

        void setupCore(WarpSystem::Core *core);
        void checkCore(void);

        bool move(int warp, Destination d);
        bool move(int warp);
        bool move(Destination d);
        bool move();

        int getShield() { return this->_shield; }
        void setShield(int shield) { this->_shield = shield; }
        int getWeaponFrequency() { return this->_weaponFrequency; }
        void setWeaponFrequency(int weaponFrequency) { this->_weaponFrequency = weaponFrequency; }
        short getRepair() { return this->_repair; }
        void setRepair(short repair) { this->_repair = repair; }

        void fire(Federation::Starfleet::Ship *target);
        void fire(Federation::Ship *target);
        void repair();
    private:
        int _side;
        short _maxWarp;
        WarpSystem::Core *_core;
        Destination _home;
        Destination _location;
        int _shield;
        int _weaponFrequency;
        short _repair;
    };
}
