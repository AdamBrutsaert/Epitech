/*
** EPITECH PROJECT, 2024
** HealthPotion.hpp
** File description:
** HealthPotion.hpp
*/

#pragma once

#include "IPotion.hpp"

class HealthPotion : public IPotion {
public:
    void use(int &health, int &power) const override;
};
