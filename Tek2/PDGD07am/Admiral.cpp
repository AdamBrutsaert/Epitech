/*
** EPITECH PROJECT, 2024
** Admiral.cpp
** File description:
** Admiral.cpp
*/

#include "Admiral.hpp"

#include <iostream>

namespace Federation::Starfleet {
    Admiral::Admiral(std::string name)
        : movePtr(&Ship::move), firePtr(&Ship::fire), _name(name)
    {
        std::cout << "Admiral " << _name << " ready for action." << std::endl;
    }

    void Admiral::fire(Ship *ship, Borg::Ship *target)
    {
        std::cout << "On order from Admiral " << this->_name << ":" << std::endl;
        (ship->*firePtr)(target);
    }

    bool Admiral::move(Ship *ship, Destination d)
    {
        return (ship->*movePtr)(d);
    }
}
