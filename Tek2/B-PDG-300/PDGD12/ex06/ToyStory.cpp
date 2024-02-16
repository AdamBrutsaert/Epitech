/*
** EPITECH PROJECT, 2024
** ToyStory.cpp
** File description:
** ToyStory.cpp
*/

#include "ToyStory.hpp"

#include <fstream>

void ToyStory::tellMeAStory(
    const std::string &filename,
    Toy &toy1,
    bool (Toy::*func1)(const std::string &),
    Toy &toy2,
    bool (Toy::*func2)(const std::string &)
)
{
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cout << "Bad Story" << std::endl;
        return;
    }

    std::cout << toy1.getAscii() << std::endl;
    std::cout << toy2.getAscii() << std::endl;

    std::string line;
    bool isToy1 = true;

    while (std::getline(file, line)) {
        bool pictured = false;

        // If it's a picture, set the picture
        if (line.find("picture:") != std::string::npos) {
            pictured = true;

            if (isToy1) {
                toy1.setAscii(line.substr(8));

                if (toy1.getLastError().type == Toy::Error::UNKNOWN)
                    std::cout << toy1.getAscii() << std::endl;
            } else {
                toy2.setAscii(line.substr(8));

                if (toy2.getLastError().type == Toy::Error::UNKNOWN)
                    std::cout << toy2.getAscii() << std::endl;
            }
        } else {
            if (isToy1) {
                (toy1.*func1)(line);
            } else {
                (toy2.*func2)(line);
            }
        }

        // Check for errors
        if (isToy1 && toy1.getLastError().type != Toy::Error::UNKNOWN) {
            std::cout << toy1.getLastError().where() << ": "
                      << toy1.getLastError().what() << std::endl;
            return;
        } else if (!isToy1 && toy2.getLastError().type != Toy::Error::UNKNOWN) {
            std::cout << toy2.getLastError().where() << ": "
                      << toy2.getLastError().what() << std::endl;
            return;
        }

        // Switch toy
        if (!pictured)
            isToy1 = !isToy1;
    }
}
