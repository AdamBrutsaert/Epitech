/*
** EPITECH PROJECT, 2024
** IPotion.hpp
** File description:
** IPotion.hpp
*/

#pragma once

class IPotion {
public:
    virtual ~IPotion() = default;

    virtual void use(int &health, int &power) const = 0;
};
