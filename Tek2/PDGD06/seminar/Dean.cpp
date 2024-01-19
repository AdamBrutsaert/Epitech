/*
** EPITECH PROJECT, 2024
** Dean.cpp
** File description:
** Dean.cpp
*/

#include "Dean.hpp"

#include <iostream>
#include <fstream>

static const char *BEVERAGES[] = {
    "Cristaline",
    "Monster",
    "Evian",
    "Red Bull",
    "Sierra Springs"
};

Dean::Dean(std::string name)
    : _name(name)
{
    std::cout << "Dean " << name << ": I'm Dean " << name << "! How do you do, fellow kids?" << std::endl;
}

Dean::~Dean()
{
    std::cout << "Dean " << this->_name << ": Time to go home." << std::endl;
}

void Dean::teachStudent(Student *student, std::string subject)
{
    if (student->learn(subject))
        return;

    std::cout << "Dean " << this->_name << ": All work and no play makes " << student->getName() << " a dull student." << std::endl;

    std::ofstream file(student->getName() + ".drink");

    if (!file)
        return;

    file << BEVERAGES[std::rand() % 5];
}

void Dean::timeCheck(void)
{
    this->_isWorking = !this->_isWorking;

    if (this->_isWorking) {
        std::cout << "Dean " << this->_name << ": Where is everyone?" << std::endl;
    } else {
        std::cout << "Dean " << this->_name << ": Don't forget to close the windows when you leave." << std::endl;
    }
}
