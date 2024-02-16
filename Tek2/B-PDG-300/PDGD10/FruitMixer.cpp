/*
** EPITECH PROJECT, 2024
** FruitMixer.cpp
** File description:
** FruitMixer.cpp
*/

#include "FruitMixer.hpp"

FruitMixer::FruitMixer()
    : _blade(nullptr)
{
}

unsigned int FruitMixer::mixFruits(FruitBox& box) const
{
    if (this->_blade == nullptr) {
        std::cout << "mixer has no blade" << std::endl;
        return 0;
    }

    unsigned int vitamins = 0;
    unsigned int length = box.nbFruits();

    for (unsigned int i = 0; i < length; i++) {
        IFruit *fruit = box.popFruit();

        if (fruit->isPeeled()) {
            vitamins += (*this->_blade)(*fruit);
            delete fruit;
        } else {
            box.pushFruit(fruit);
        }
    }

    return vitamins;
}

void FruitMixer::setBlade(IBlade* blade)
{
    _blade = blade;
}
