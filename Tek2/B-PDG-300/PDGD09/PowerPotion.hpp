/*
** EPITECH PROJECT, 2024
** PowerPotion.hpp
** File description:
** PowerPotion.hpp
*/

#pragma once

#include "IPotion.hpp"

class PowerPotion : public IPotion {
public:
    void use(int &health, int &power) const override;
};
