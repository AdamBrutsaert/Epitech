/*
** EPITECH PROJECT, 2024
** FruitBox.cpp
** File description:
** FruitBox.cpp
*/

#include "FruitBox.hpp"

FruitBox::FruitBox(unsigned int size)
    : _size(size)
{
}

FruitBox::~FruitBox()
{
    for (auto it = this->_fruits.begin(); it != this->_fruits.end(); it++)
        delete *it;
}

unsigned int FruitBox::getSize() const
{
    return this->_size;
}

unsigned int FruitBox::nbFruits() const
{
    return this->_fruits.size();
}

bool FruitBox::pushFruit(IFruit *fruit)
{
    if (this->_fruits.size() == this->_size)
        return false;

    for (auto it = this->_fruits.begin(); it != this->_fruits.end(); it++)
        if (*it == fruit)
            return false;

    this->_fruits.push_back(fruit);
    return true;
}

IFruit *FruitBox::popFruit()
{
    if (this->_fruits.size() == 0)
        return nullptr;
    IFruit *fruit = this->_fruits.front();
    this->_fruits.pop_front();
    return fruit;
}

const std::deque<IFruit *> &FruitBox::getFruits() const
{
    return this->_fruits;
}

std::ostream& operator<<(std::ostream& os, const FruitBox& box)
{
    auto fruits = box.getFruits();

    os << "[";

    for (auto it = fruits.begin(); it != fruits.end(); it++) {
        if (it != fruits.begin())
            os << ", ";
        os << **it;
    }

    return os << "]";
}
