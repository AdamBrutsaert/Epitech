/*
** EPITECH PROJECT, 2024
** IFruit.cpp
** File description:
** IFruit.cpp
*/

#include "IFruit.hpp"

std::ostream& operator<<(std::ostream& os, const IFruit& fruit)
{
    return os << "[name: \"" << fruit.getName()
        << "\", vitamins: " << fruit.getVitamins()
        << ", peeled: " << (fruit.isPeeled() ? "true" : "false") << "]";
}
