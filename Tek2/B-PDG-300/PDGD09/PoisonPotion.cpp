/*
** EPITECH PROJECT, 2024
** PoisonPotion.cpp
** File description:
** PoisonPotion.cpp
*/

#include "PoisonPotion.hpp"

#include <algorithm>

void PoisonPotion::use(int &health, [[maybe_unused]] int &power) const
{
    health = std::max(health - 50, 0);
}
