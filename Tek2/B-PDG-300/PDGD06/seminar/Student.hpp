/*
** EPITECH PROJECT, 2024
** Student.hpp
** File description:
** Student.hpp
*/

#pragma once

#include <string>
#include <cstdint>

class Student {
public:
    Student(std::string name);
    ~Student();

    bool learn(std::string message);
    void drink(std::string beverage);

    const std::string& getName() const { return this->_name; }

private:
    std::string _name;
    int8_t _energy;
};
