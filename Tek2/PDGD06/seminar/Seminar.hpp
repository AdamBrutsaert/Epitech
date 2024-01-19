/*
** EPITECH PROJECT, 2024
** Seminar.hpp
** File description:
** Seminar.hpp
*/

#pragma once

#include "Assistant.hpp"
#include "Dean.hpp"

#include <vector>
#include <optional>

class Seminar {
public:
    Seminar();
    ~Seminar() = default;

    void addDean(Dean* dean);
    void addAssistant(Assistant* assistant);
    void addStudent(Student* student);

    void run(void);

private:
    std::optional<Dean *> _dean;
    std::vector<Assistant *> _assistants;
    std::vector<Student *> _students;
};
