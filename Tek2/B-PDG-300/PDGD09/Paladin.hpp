/*
** EPITECH PROJECT, 2024
** Paladin.hpp
** File description:
** Paladin.hpp
*/

#pragma once

#include "Knight.hpp"
#include "Priest.hpp"

class Paladin : public Knight, public Priest {
public:
    Paladin(const std::string &name, int power);
    virtual ~Paladin();

    virtual int attack() override;
    virtual int special() override;
    virtual void rest() override;
};
