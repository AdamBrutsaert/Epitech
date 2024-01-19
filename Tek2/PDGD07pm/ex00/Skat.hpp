/*
** EPITECH PROJECT, 2024
** Skat.hpp
** File description:
** Skat.hpp
*/

#pragma once

#include <string>

class Skat
{
public:
    Skat(const std::string &name = "bob", int stimPaks = 15);
    ~Skat() = default;

    int &stimPaks() { return this->_stimPaks; }
    const std::string &name() { return this->_name; }

    void shareStimPaks(int number, int &stock);
    void addStimPaks(unsigned int number);
    void useStimPaks();
    void status();
private:
    std::string _name;
    int _stimPaks;
};
