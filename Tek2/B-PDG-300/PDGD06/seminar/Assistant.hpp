/*
** EPITECH PROJECT, 2024
** Assistant.hpp
** File description:
** Assistant.hpp
*/

#pragma once

#include "Student.hpp"

#include <cstdint>

class Assistant {
public:
    Assistant(intmax_t id);
    ~Assistant();

    void giveDrink(Student *student, std::string beverage);
    std::string readDrink(std::string name);

    void helpStudent(Student *student);

    void timeCheck(void);

    intmax_t getId() const { return this->_id; }
private:
    intmax_t _id;
    bool _isWorking;
};
