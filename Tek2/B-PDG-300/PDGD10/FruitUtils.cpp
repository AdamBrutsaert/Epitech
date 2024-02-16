/*
** EPITECH PROJECT, 2024
** FruitUtils.cpp
** File description:
** FruitUtils.cpp
*/

#include "FruitUtils.hpp"

#include "ABerry.hpp"
#include "ACitrus.hpp"
#include "Lemon.hpp"

void FruitUtils::sort(FruitBox &unsorted, FruitBox &lemon, FruitBox &citrus, FruitBox &berry)
{
    size_t nbFruits = unsorted.nbFruits();

    for (unsigned int i = 0; i < nbFruits; i++) {
        auto fruit = unsorted.popFruit();

        if (dynamic_cast<Lemon *>(fruit) != nullptr) {
            if (!lemon.pushFruit(fruit))
                unsorted.pushFruit(fruit);
        } else if (dynamic_cast<ACitrus *>(fruit) != nullptr) {
            if (!citrus.pushFruit(fruit))
                unsorted.pushFruit(fruit);
        } else if (dynamic_cast<ABerry *>(fruit) != nullptr) {
            if (!berry.pushFruit(fruit))
                unsorted.pushFruit(fruit);
        } else {
            unsorted.pushFruit(fruit);
        }
    }
}

FruitBox **FruitUtils::pack(IFruit **fruits, unsigned int boxSize)
{
    // Count the number of fruits
    size_t nbFruits = 0;

    while (fruits[nbFruits] != nullptr)
        nbFruits++;

    // Create the boxes
    size_t nbBoxes = nbFruits / boxSize + (nbFruits % boxSize != 0) + 1;
    FruitBox **boxes = new FruitBox *[nbBoxes];

    boxes[nbBoxes - 1] = nullptr;
    for (unsigned int i = 0; i + 1 < nbBoxes; i++)
        boxes[i] = new FruitBox(boxSize);

    // Fill the boxes
    for (unsigned int i = 0; i < nbFruits; i++)
        boxes[i / boxSize]->pushFruit(fruits[i]);

    return boxes;
}

IFruit **FruitUtils::unpack(FruitBox **fruitBoxes)
{
    // Count the number of fruits
    size_t nbFruits = 0;

    for (unsigned int i = 0; fruitBoxes[i] != nullptr; i++)
        nbFruits += fruitBoxes[i]->nbFruits();

    // Create the fruits array
    IFruit **fruits = new IFruit *[nbFruits + 1];
    fruits[nbFruits] = nullptr;

    // Fill the fruits array
    for (unsigned int i = 0, j = 0; fruitBoxes[i] != nullptr; i++) {
        for (auto fruit = fruitBoxes[i]->popFruit(); fruit != nullptr; fruit = fruitBoxes[i]->popFruit(), j++)
            fruits[j] = fruit;
    }

    return fruits;
}
