/*
** EPITECH PROJECT, 2024
** Enchanter.hpp
** File description:
** Enchanter.hpp
*/

#pragma once

#include "Peasant.hpp"

class Enchanter : virtual public Peasant {
public:
    Enchanter(const std::string &name, int power);
    virtual ~Enchanter();

    virtual int attack();
    virtual int special();
    virtual void rest();
};
