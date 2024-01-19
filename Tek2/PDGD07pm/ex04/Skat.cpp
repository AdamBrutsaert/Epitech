/*
** EPITECH PROJECT, 2024
** Skat.cpp
** File description:
** Skat.cpp
*/

#include "Skat.hpp"

#include <iostream>

Skat::Skat(const std::string &name, int stimPaks,
           int serial, int x, int y, Phaser::AmmoType type)
    : _name(name), _stimPaks(stimPaks),
      _kreogCom(new KreogCom(x, y, serial)), _phaser(new Phaser(20, type))
{
}

Skat::~Skat()
{
    delete this->_kreogCom;
    delete this->_phaser;
}

void Skat::shareStimPaks(int number, int &stock)
{
    if (this->_stimPaks < number) {
        std::cout << "Don't be greedy" << std::endl;
        return;
    }
    stock += number;
    this->_stimPaks -= number;
    std::cout << "Keep the change." << std::endl;
}

void Skat::addStimPaks(unsigned int number)
{
    if (number == 0) {
        std::cout << "Hey boya, did you forget something?" << std::endl;
        return;
    }
    this->_stimPaks += number;
}

void Skat::useStimPaks()
{
    if (this->_stimPaks == 0) {
        std::cout << "Mediiiiiic" << std::endl;
        return;
    }
    this->_stimPaks -= 1;
    std::cout << "Time to kick some ass and chew bubble gum." << std::endl;
}

void Skat::status()
{
    std::cout << "Soldier " << this->_name << " reporting "
              << this->_stimPaks << " stimpaks remaining sir!" << std::endl;
}
