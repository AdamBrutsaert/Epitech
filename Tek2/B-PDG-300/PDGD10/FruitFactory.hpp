/*
** EPITECH PROJECT, 2024
** FruitFactory.hpp
** File description:
** FruitFactory.hpp
*/

#pragma once

#include "IFruit.hpp"

#include <map>

class FruitFactory {
public:
    ~FruitFactory();

    void registerFruit(IFruit *fruit);
    void unregisterFruit(const std::string &name);
    IFruit *createFruit(const std::string &name) const;
private:
    std::map<std::string, IFruit *> _fruits;
};
