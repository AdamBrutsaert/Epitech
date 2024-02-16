/*
** EPITECH PROJECT, 2024
** AFruit.cpp
** File description:
** AFruit.cpp
*/

#include "AFruit.hpp"

AFruit::AFruit()
    : _peeled(false), _vitamins(0)
{
}

AFruit::AFruit(bool peeled, unsigned int vitamins)
    : _peeled(peeled), _vitamins(vitamins)
{
}

unsigned int AFruit::getVitamins() const
{
    if (!this->isPeeled())
        return 0;
    return this->_vitamins;
}

bool AFruit::isPeeled() const
{
    return this->_peeled;
}

void AFruit::peel()
{
    this->_peeled = true;
}
