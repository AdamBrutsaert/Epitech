/*
** EPITECH PROJECT, 2024
** BloodOrange.cpp
** File description:
** BloodOrange.cpp
*/

#include "BloodOrange.hpp"

BloodOrange::BloodOrange()
    : Orange(false, 6)
{
}

std::string BloodOrange::getName() const
{
    return "blood orange";
}

IFruit *BloodOrange::clone() const
{
    return new BloodOrange(*this);
}
