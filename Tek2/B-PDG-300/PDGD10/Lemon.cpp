/*
** EPITECH PROJECT, 2024
** Lemon.cpp
** File description:
** Lemon.cpp
*/

#include "Lemon.hpp"

Lemon::Lemon()
    : ACitrus(false, 4)
{
}

std::string Lemon::getName() const
{
    return "lemon";
}

IFruit *Lemon::clone() const
{
    return new Lemon(*this);
}
