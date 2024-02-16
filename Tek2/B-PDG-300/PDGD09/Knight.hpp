/*
** EPITECH PROJECT, 2024
** Knight.hpp
** File description:
** Knight.hpp
*/

#pragma once

#include "Peasant.hpp"

class Knight : virtual public Peasant {
public:
    Knight(const std::string &name, int power);
    virtual ~Knight();

    virtual int attack() override;
    virtual int special() override;
    virtual void rest() override;
};
