/*
** EPITECH PROJECT, 2024
** FruitBox.hpp
** File description:
** FruitBox.hpp
*/

#pragma once

#include "IFruit.hpp"

#include <deque>

class FruitBox {
public:
    FruitBox(unsigned int size);
    FruitBox(const FruitBox &box) = delete;
    FruitBox &operator=(const FruitBox &box) = delete;
    ~FruitBox();

    unsigned int getSize() const;
    unsigned int nbFruits() const;
    bool pushFruit(IFruit *fruit);
    IFruit *popFruit();

    const std::deque<IFruit *> &getFruits() const;
private:
    unsigned int _size;
    std::deque<IFruit *> _fruits;
};

std::ostream& operator<<(std::ostream& os, const FruitBox& box);
