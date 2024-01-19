/*
** EPITECH PROJECT, 2024
** Exam.cpp
** File description:
** Exam.cpp
*/

#include "Exam.hpp"

#include <iostream>

bool Exam::cheat = false;

Exam::Exam(bool *cheat)
{
    Exam::cheat = *cheat;
}

void Exam::start(int n)
{
    std::cout << "[The exam is starting]" << std::endl;
    std::cout << n << " Klingon vessels appeared out of nowhere." << std::endl;
    std::cout << "they are fully armed and shielded" << std::endl;

    if (this->isCheating()) {
        std::cout << "What the... someone changed the parameters of the exam !" << std::endl;
    } else {
        std::cout << "This exam is hard... you lost again." << std::endl;
    }
}
