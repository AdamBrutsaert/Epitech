/*
** EPITECH PROJECT, 2024
** Squad.hpp
** File description:
** Squad.hpp
*/

#pragma once

#include "Phaser.hpp"
#include "Skat.hpp"

class Squad {
public:
    Squad(int posXBegin, int posYBegin, Phaser::AmmoType ammoType,
          int size = 5);
    ~Squad();

    void fire();
    void localisation();

    Skat **skats();
    Skat *at(int idx);
    int size();

private:
    int _size;
    Skat **_skats;
};

void foreach(Skat **beginIdx, void (Skat::*actionPtr)());
