/*
** EPITECH PROJECT, 2024
** Coconut.cpp
** File description:
** Coconut.cpp
*/

#include "Coconut.hpp"

Coconut::Coconut()
    : ANut(false, 4)
{
}

std::string Coconut::getName() const
{
    return "coconut";
}

IFruit *Coconut::clone() const
{
    return new Coconut(*this);
}
