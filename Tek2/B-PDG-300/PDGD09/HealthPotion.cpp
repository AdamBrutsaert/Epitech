/*
** EPITECH PROJECT, 2024
** HealthPotion.cpp
** File description:
** HealthPotion.cpp
*/

#include "HealthPotion.hpp"

#include <algorithm>

void HealthPotion::use(int &health, [[maybe_unused]] int &power) const
{
    health = std::min(health + 50, 100);
}
