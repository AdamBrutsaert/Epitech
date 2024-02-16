/*
** EPITECH PROJECT, 2024
** ABerry.cpp
** File description:
** ABerry.cpp
*/

#include "ABerry.hpp"

bool ABerry::isPeeled() const
{
    return true;
}

ABerry::ABerry(bool peeled, unsigned int vitamins)
    : AFruit(peeled, vitamins)
{
}
