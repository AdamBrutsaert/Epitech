/*
** EPITECH PROJECT, 2024
** PoisonPotion.hpp
** File description:
** PoisonPotion.hpp
*/

#pragma once

#include "IPotion.hpp"

class PoisonPotion : public IPotion {
public:
    void use(int &health, int &power) const override;
};
