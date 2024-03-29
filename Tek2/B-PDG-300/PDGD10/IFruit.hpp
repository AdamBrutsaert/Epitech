/*
** EPITECH PROJECT, 2024
** IFruit.hpp
** File description:
** IFruit.hpp
*/

#pragma once

#include <string>
#include <iostream>

class IFruit {
public:
    virtual ~IFruit() = default;

    virtual unsigned int getVitamins() const = 0;
    virtual std::string getName() const = 0;
    virtual bool isPeeled() const = 0;
    virtual void peel() = 0;
    virtual IFruit *clone() const = 0;
};

std::ostream& operator<<(std::ostream& os, const IFruit& fruit);
