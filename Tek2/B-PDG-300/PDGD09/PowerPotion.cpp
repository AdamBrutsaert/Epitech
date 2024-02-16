/*
** EPITECH PROJECT, 2024
** PowerPotion.cpp
** File description:
** PowerPotion.cpp
*/

#include "PowerPotion.hpp"

#include <algorithm>

void PowerPotion::use([[maybe_unused]] int &health, int &power) const
{
    power = std::min(power + 50, 100);
}
