/*
** EPITECH PROJECT, 2024
** Seminar.cpp
** File description:
** Seminar.cpp
*/

#include "Seminar.hpp"

#include <algorithm>
#include <iostream>
#include <numeric>

Seminar::Seminar()
    : _dean(std::nullopt), _assistants(), _students()
{
    _assistants.reserve(2);
    _students.reserve(5);
}

void Seminar::addDean(Dean *dean)
{
    if (this->_dean.has_value()) {
        std::cout << "Seminar: There can only be one Dean of Studies.\n";
        return;
    }

    this->_dean = dean;
    std::cout << "Seminar: Dean " << dean->getName() << " is here.\n";
}

void Seminar::addAssistant(Assistant *assistant)
{
    if (std::find(this->_assistants.begin(), this->_assistants.end(), assistant) != this->_assistants.end()) {
        std::cout << "Seminar: Assistant " << assistant->getId() << " is already registered.\n";
        return;
    }

    if (this->_assistants.size() == 2) {
        std::cout << "Seminar: There is only room for two Teaching Assistants.\n";
        return;
    }

    this->_assistants.push_back(assistant);
    std::cout << "Seminar: Assistant " << assistant->getId() << " joined the pedagogical team.\n";
}

void Seminar::addStudent(Student *student)
{
    if (std::find(this->_students.begin(), this->_students.end(), student) != this->_students.end()) {
        std::cout << "Seminar: Student " << student->getName() << " is already registered.\n";
        return;
    }

    if (this->_students.size() == 5) {
        std::cout << "Seminar: There is only room for five Students.\n";
        return;
    }

    this->_students.push_back(student);
    std::cout << "Seminar: Student " << student->getName() << " joined the seminar.\n";
}

void Seminar::run(void)
{
    if (!this->_dean.has_value() || this->_assistants.empty() || this->_students.empty()) {
        std::cout << "Seminar: A C++ seminar needs at least one Dean of Studies, one Assistant and one Student.\n";
        return;
    }

    std::cout << "Seminar: Begining 6th day of seminar.\n";

    std::cout << "Dean of Studies: " << this->_dean.value()->getName() << "\n";

    std::cout << "Teaching assistants: ";
    for (size_t i = 0; i < this->_assistants.size(); i++) {
        if (i != 0)
            std::cout << ", ";
        std::cout << this->_assistants[i]->getId();
    }
    std::cout << "\n";

    std::cout << "Students: ";
    for (size_t i = 0; i < this->_students.size(); i++) {
        if (i != 0)
            std::cout << ", ";
        std::cout << this->_students[i]->getName();
    }
    std::cout << "\n";

    this->_dean.value()->timeCheck();
    for (const auto &assistant : this->_assistants)
        assistant->timeCheck();


    size_t assistantIndex = 0;

    for (size_t _ = 0; _ < 5; _++)
    {
        for (const auto& student : this->_students)
        {
            this->_dean.value()->teachStudent(student, "I'm learning C++!");
            this->_assistants[assistantIndex]->helpStudent(student);

            assistantIndex = (assistantIndex + 1) % this->_assistants.size();
        }
    }

    this->_dean.value()->timeCheck();
    for (const auto &assistant : this->_assistants)
        assistant->timeCheck();
}
