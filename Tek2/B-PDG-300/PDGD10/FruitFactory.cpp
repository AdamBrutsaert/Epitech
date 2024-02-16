/*
** EPITECH PROJECT, 2024
** FruitFactory.cpp
** File description:
** FruitFactory.cpp
*/

#include "FruitFactory.hpp"

FruitFactory::~FruitFactory()
{
    for (auto &fruit : this->_fruits)
        delete fruit.second;
}

void FruitFactory::registerFruit(IFruit *fruit)
{
    if (this->_fruits[fruit->getName()])
        delete this->_fruits[fruit->getName()];

    this->_fruits[fruit->getName()] = fruit;
}

void FruitFactory::unregisterFruit(const std::string &name)
{
    if (this->_fruits[name])
        delete this->_fruits[name];

    this->_fruits.erase(name);
}

IFruit *FruitFactory::createFruit(const std::string &name) const
{
    auto value = this->_fruits.find(name);

    if (value == this->_fruits.end())
        return nullptr;

    return value->second->clone();
}
