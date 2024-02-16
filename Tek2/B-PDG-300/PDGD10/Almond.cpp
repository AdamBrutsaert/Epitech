/*
** EPITECH PROJECT, 2024
** Almond.cpp
** File description:
** Almond.cpp
*/

#include "Almond.hpp"

Almond::Almond()
    : ANut(false, 2)
{
}

std::string Almond::getName() const
{
    return "almond";
}

IFruit *Almond::clone() const
{
    return new Almond(*this);
}
