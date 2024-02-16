/*
** EPITECH PROJECT, 2024
** Lemon.hpp
** File description:
** Lemon.hpp
*/

#pragma once

#include "ACitrus.hpp"

class Lemon : public ACitrus {
public:
    Lemon();

    virtual std::string getName() const override;
    virtual IFruit *clone() const override;
};
