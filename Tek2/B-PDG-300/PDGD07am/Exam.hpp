/*
** EPITECH PROJECT, 2024
** Exam.hpp
** File description:
** Exam.hpp
*/

#pragma once

class Exam {
public:
    Exam(bool *cheat);
    ~Exam() = default;

    void start(int n);
    static bool isCheating() { return cheat; };

public:
    void (Exam::*kobayashiMaru)(int);
    static bool cheat;
};
