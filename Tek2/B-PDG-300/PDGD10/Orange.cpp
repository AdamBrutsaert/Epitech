/*
** EPITECH PROJECT, 2024
** Orange.cpp
** File description:
** Orange.cpp
*/

#include "Orange.hpp"

Orange::Orange()
    : ACitrus(false, 7)
{
}

Orange::Orange(bool peeled, unsigned int vitamins)
    : ACitrus(peeled, vitamins)
{
}

std::string Orange::getName() const
{
    return "orange";
}

IFruit *Orange::clone() const
{
    return new Orange(*this);
}
