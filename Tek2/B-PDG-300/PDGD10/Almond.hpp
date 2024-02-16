/*
** EPITECH PROJECT, 2024
** Almond.hpp
** File description:
** Almond.hpp
*/

#pragma once

#include "ANut.hpp"

class Almond : public ANut {
public:
    Almond();

    virtual std::string getName() const override;
    virtual IFruit *clone() const override;
};
