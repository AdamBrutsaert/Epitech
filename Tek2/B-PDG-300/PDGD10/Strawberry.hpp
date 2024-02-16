/*
** EPITECH PROJECT, 2024
** Strawberry.hpp
** File description:
** Strawberry.hpp
*/

#pragma once

#include "ABerry.hpp"

class Strawberry : public ABerry {
public:
    Strawberry();

    virtual std::string getName() const override;
    virtual IFruit *clone() const override;
};
