/*
** EPITECH PROJECT, 2024
** BorgQueen.cpp
** File description:
** BorgQueen.cpp
*/

#include "BorgQueen.hpp"

namespace Borg {
    BorgQueen::BorgQueen()
        : movePtr(&Ship::move), firePtr(&Ship::fire), destroyPtr(&Ship::fire)
    {
    }

    bool BorgQueen::move(Borg::Ship *ship, Destination dest)
    {
        return (ship->*movePtr)(dest);
    }

    void BorgQueen::fire(Borg::Ship *ship, Federation::Starfleet::Ship *target)
    {
        (ship->*firePtr)(target);
    }

    void BorgQueen::destroy(Borg::Ship *ship, Federation::Ship *target)
    {
        (ship->*destroyPtr)(target);
    }
}
