/*
** EPITECH PROJECT, 2024
** Orange.hpp
** File description:
** Orange.hpp
*/

#pragma once

#include "ACitrus.hpp"

class Orange : public ACitrus {
public:
    Orange();

    virtual std::string getName() const override;
    virtual IFruit *clone() const override;
protected:
    Orange(bool peeled, unsigned int vitamins);
};
