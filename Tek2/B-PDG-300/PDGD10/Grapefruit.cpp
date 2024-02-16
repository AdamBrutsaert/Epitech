/*
** EPITECH PROJECT, 2024
** Grapefruit.cpp
** File description:
** Grapefruit.cpp
*/

#include "Grapefruit.hpp"

Grapefruit::Grapefruit()
    : ACitrus(false, 5)
{
}

std::string Grapefruit::getName() const
{
    return "grapefruit";
}

IFruit *Grapefruit::clone() const
{
    return new Grapefruit(*this);
}
