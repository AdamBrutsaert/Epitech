/*
** EPITECH PROJECT, 2024
** Skat.hpp
** File description:
** Skat.hpp
*/

#pragma once

#include <string>

#include "Phaser.hpp"
#include "KreogCom.hpp"

class Skat
{
public:
    Skat(const std::string &name, int stimPaks,
         int serial, int x, int y, Phaser::AmmoType type);
    ~Skat();

    int &stimPaks() { return this->_stimPaks; }
    const std::string &name() { return this->_name; }

    void shareStimPaks(int number, int &stock);
    void addStimPaks(unsigned int number);
    void useStimPaks();
    void status();

    void fire() { this->_phaser->fire(); }
    void locate() const { this->_kreogCom->ping(); }
    void reload() { this->_phaser->reload(); }
    KreogCom &com() { return *this->_kreogCom; }

private:
    std::string _name;
    int _stimPaks;
    KreogCom *_kreogCom;
    Phaser *_phaser;
};
