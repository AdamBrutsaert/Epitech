/*
** EPITECH PROJECT, 2024
** ex00.cpp
** File description:
** ex00.cpp
*/

#include "../ex00/Toy.hpp"

#include <iostream>

int main()
{
    Toy toto;
    Toy ET(Toy::ALIEN, "green", "./alien.txt");

    toto.setName("TOTO !");

    if (toto.getType() == Toy::BASIC_TOY)
        std::cout << "basic toy: " << toto.getName() << std::endl
                  << toto.getAscii() << std::endl;

    if (ET.getType() == Toy::ALIEN)
        std::cout << "this alien is: " << ET.getName() << std::endl
                  << ET.getAscii() << std::endl;

    return 0;
}
