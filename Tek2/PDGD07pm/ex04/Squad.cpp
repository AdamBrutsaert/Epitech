/*
** EPITECH PROJECT, 2024
** Squad.cpp
** File description:
** Squad.cpp
*/

#include "Squad.hpp"
#include "Sounds.hpp"

const std::string Sounds::Regular = "Bang";
const std::string Sounds::Plasma = "Fwooosh";
const std::string Sounds::Rocket = "Boouuuuuum";

Squad::Squad(int posXBegin, int posYBegin, Phaser::AmmoType ammoType, int size)
    : _size(size)
{
    Skat *lastSkat = nullptr;

    this->_skats = new Skat*[size + 1];

    for (int i = 0; i < size; i++) {
        _skats[i] = new Skat(
            "bob",
            15,
            i,
            posXBegin + 10 * i,
            posYBegin + 15 * i,
            ammoType
        );

        if (lastSkat != nullptr)
            lastSkat->com().addCom(&_skats[i]->com());

        lastSkat = _skats[i];
    }

    this->_skats[size] = nullptr;
}

Squad::~Squad()
{
    for (int i = 0; i < this->_size; i++)
        delete this->_skats[i];
    delete[] this->_skats;
}

void Squad::fire()
{
    for (int i = 0; i < this->_size; i++)
        this->_skats[i]->fire();
}

void Squad::localisation()
{
    for (int i = 0; i < this->_size; i++)
        this->_skats[i]->locate();
}

Skat **Squad::skats()
{
    return this->_skats;
}

Skat *Squad::at(int idx)
{
    if (idx >= this->_size || idx < 0)
        return nullptr;
    return this->_skats[idx];
}

int Squad::size()
{
    return this->_size;
}

void foreach(Skat **beginIdx, void (Skat::*actionPtr)())
{
    for (size_t i = 0; beginIdx[i] != nullptr; i++)
        (beginIdx[i]->*actionPtr)();
}
