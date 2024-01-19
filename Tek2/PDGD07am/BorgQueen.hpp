/*
** EPITECH PROJECT, 2024
** BorgQueen.hpp
** File description:
** BorgQueen.hpp
*/

#pragma once

#include "Borg.hpp"

namespace Borg {
    class BorgQueen {
    public:
        BorgQueen();
        ~BorgQueen() = default;

        bool (Ship::*movePtr)(Destination);
        void (Ship::*firePtr)(Federation::Starfleet::Ship *);
        void (Ship::*destroyPtr)(Federation::Ship *);

        bool move(Borg::Ship *ship, Destination dest);
        void fire(Borg::Ship *ship, Federation::Starfleet::Ship *target);
        void destroy(Borg::Ship *ship, Federation::Ship *target);
    };
}
