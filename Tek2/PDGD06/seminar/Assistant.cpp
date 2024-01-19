/*
** EPITECH PROJECT, 2024
** Assistant.cpp
** File description:
** Assistant.cpp
*/

#include "Assistant.hpp"

#include <iostream>
#include <fstream>

Assistant::Assistant(intmax_t id)
    : _id(id), _isWorking(false)
{
    std::cout << "Assistant " << this->_id << ": 'morning everyone *sip coffee*" << std::endl;
}

Assistant::~Assistant()
{
    std::cout << "Assistant " << this->_id << ": see you tomorrow at 9.00 *sip coffee*" << std::endl;
}

void Assistant::giveDrink(Student *student, std::string beverage)
{
    std::cout << "Assistant " << this->_id << ": drink this, " << student->getName() << " *sip coffee*" << std::endl;
    student->drink(beverage);
}

std::string Assistant::readDrink(std::string name)
{
    std::string filename = name + ".drink";
    std::ifstream file(filename);

    if (!file)
        return "";

    std::string drink;
    std::getline(file, drink);

    file.close();
    std::remove(filename.c_str());

    std::cout << "Assistant " << this->_id << ": " << name << " needs a " << drink << " *sip coffee*" << std::endl;

    return drink;
}

void Assistant::helpStudent(Student *student)
{
    const auto beverage = this->readDrink(student->getName());

    if (beverage.empty()) {
        std::cout << "Assistant " << this->_id << ": " << student->getName() << " seems fine *sip coffee*" << std::endl;
    } else {
        giveDrink(student, beverage);
    }
}

void Assistant::timeCheck(void)
{
    this->_isWorking = !this->_isWorking;

    if (this->_isWorking) {
        std::cout << "Assistant " << this->_id << ": Time to teach some serious business *sip coffee*" << std::endl;
    } else {
        std::cout << "Assistant " << this->_id << ": Enough teaching for today *sip coffee*" << std::endl;
    }
}
