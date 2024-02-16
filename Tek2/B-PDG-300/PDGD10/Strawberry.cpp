/*
** EPITECH PROJECT, 2024
** Strawberry.cpp
** File description:
** Strawberry.cpp
*/

#include "Strawberry.hpp"

Strawberry::Strawberry()
    : ABerry(true, 6)
{
}

std::string Strawberry::getName() const
{
    return "strawberry";
}

IFruit *Strawberry::clone() const
{
    return new Strawberry(*this);
}
