/*
** EPITECH PROJECT, 2024
** ex03.cpp
** File description:
** ex03.cpp
*/

#include "../ex03/Toy.hpp"
#include "../ex03/Buzz.hpp"
#include "../ex03/Woody.hpp"

#include <iostream>
#include <memory>

int main()
{
    std::unique_ptr<Toy> b(new Buzz("buzziiiii"));
    std::unique_ptr<Toy> w(new Woody("wood"));
    std::unique_ptr<Toy> t(new Toy(Toy::ALIEN, "ET", "alien.txt"));

    b->speak("To the code, and beyond !!!!!!!!");
    w->speak("There's a snake in my boot.");
    t->speak("the claaaaaaw");

    return 0;
}
