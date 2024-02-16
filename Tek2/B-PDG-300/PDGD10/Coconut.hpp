/*
** EPITECH PROJECT, 2024
** Coconut.hpp
** File description:
** Coconut.hpp
*/

#pragma once

#include "ANut.hpp"

class Coconut : public ANut {
public:
    Coconut();

    virtual std::string getName() const override;
    virtual IFruit *clone() const override;
};
