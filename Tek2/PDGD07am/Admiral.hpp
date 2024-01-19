/*
** EPITECH PROJECT, 2024
** Admiral.hpp
** File description:
** Admiral.hpp
*/

#pragma once

#include "Federation.hpp"

#include <string>

namespace Federation::Starfleet {
    class Admiral {
    public:
        Admiral(std::string name);
        ~Admiral() = default;

        bool (Ship::*movePtr)(Destination);
        void (Ship::*firePtr)(Borg::Ship *);

        void fire(Ship *ship, Borg::Ship *target);
        bool move(Ship *ship, Destination d);
    private:
        std::string _name;
    };
}
