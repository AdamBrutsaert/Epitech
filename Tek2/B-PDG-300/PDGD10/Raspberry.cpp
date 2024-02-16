/*
** EPITECH PROJECT, 2024
** Raspberry.cpp
** File description:
** Raspberry.cpp
*/

#include "Raspberry.hpp"

Raspberry::Raspberry()
    : ABerry(true, 5)
{
}

std::string Raspberry::getName() const
{
    return "raspberry";
}

IFruit *Raspberry::clone() const
{
    return new Raspberry(*this);
}
