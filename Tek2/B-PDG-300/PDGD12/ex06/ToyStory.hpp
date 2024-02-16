/*
** EPITECH PROJECT, 2024
** ToyStory.hpp
** File description:
** ToyStory.hpp
*/

#pragma once

#include "Toy.hpp"

class ToyStory {
public:
    static void tellMeAStory(
        const std::string &filename,
        Toy &toy1,
        bool (Toy::*func1)(const std::string &),
        Toy &toy2,
        bool (Toy::*func2)(const std::string &)
    );
};
