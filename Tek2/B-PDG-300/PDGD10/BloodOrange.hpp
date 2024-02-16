/*
** EPITECH PROJECT, 2024
** BloodOrange.hpp
** File description:
** BloodOrange.hpp
*/

#pragma once

#include "Orange.hpp"

class BloodOrange : public Orange {
public:
    BloodOrange();

    virtual std::string getName() const override;
    virtual IFruit *clone() const override;
};
