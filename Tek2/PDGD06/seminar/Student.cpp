/*
** EPITECH PROJECT, 2024
** Student.cpp
** File description:
** Student.cpp
*/

#include "Student.hpp"

#include <algorithm>
#include <iostream>

static void replaceAll(std::string &str, const std::string& from, const std::string& to)
{
    size_t pos = 0;

    while ((pos = str.find(from, pos)) != std::string::npos) {
        str.replace(pos, from.length(), to);
        pos += to.length();
    }
}

Student::Student(std::string name)
    : _name(name), _energy(100)
{
    std::cout << "Student " << this->_name << ": I'm ready to learn C++." << std::endl;
}

Student::~Student()
{
    std::cout << "Student " << this->_name << ": Wow, much learning today, very smart, such C++." << std::endl;
}

bool Student::learn(std::string message)
{
    if (this->_energy >= 42) {
        this->_energy -= 42;
        std::cout << "Student " << this->_name << ": " << message << std::endl;
        this->_energy = std::clamp<int8_t>(this->_energy, 0, 100);
        return true;
    }

    replaceAll(message, "C++", "shit");
    std::cout << "Student " << this->_name << ": " << message << std::endl;
    return false;
}

void Student::drink(std::string beverage)
{
    if (beverage == "Red Bull") {
        std::cout << "Student " << this->_name << ": Red Bull gives you wings!" << std::endl;
        this->_energy += 32;
    } else if (beverage == "Monster") {
        std::cout << "Student " << this->_name << ": Unleash The Beast!" << std::endl;
        this->_energy += 64;
    } else {
        std::cout << "Student " << this->_name << ": ah, yes... enslaved moisture." << std::endl;
        this->_energy += 1;
    }

    this->_energy = std::clamp<int8_t>(this->_energy, 0, 100);
}
