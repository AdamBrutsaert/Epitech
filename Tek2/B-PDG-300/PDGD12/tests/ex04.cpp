/*
** EPITECH PROJECT, 2024
** ex03.cpp
** File description:
** ex03.cpp
*/

#include "../ex04/Toy.hpp"

int main()
{
    Toy a(Toy::BASIC_TOY, "REX", "rex.txt");

    std::cout << a;
    a << "\\o/";
    std::cout << a;

    return 0;
}
