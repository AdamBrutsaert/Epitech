/*
** EPITECH PROJECT, 2024
** Grapefruit.hpp
** File description:
** Grapefruit.hpp
*/

#pragma once

#include "ACitrus.hpp"

class Grapefruit : public ACitrus {
public:
    Grapefruit();

    virtual std::string getName() const override;
    virtual IFruit *clone() const override;
};
