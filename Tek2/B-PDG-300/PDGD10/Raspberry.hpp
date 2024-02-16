/*
** EPITECH PROJECT, 2024
** Raspberry.hpp
** File description:
** Raspberry.hpp
*/

#pragma once

#include "ABerry.hpp"

class Raspberry : public ABerry {
public:
    Raspberry();

    virtual std::string getName() const override;
    virtual IFruit *clone() const override;
};
