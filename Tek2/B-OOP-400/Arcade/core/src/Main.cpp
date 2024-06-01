/*
** EPITECH PROJECT, 2024
** Main.cpp
** File description:
** Main.cpp
*/

#include "Core.hpp"

#include <iostream>

int main(int argc, char **argv, char **env)
{
    if (*env == nullptr) {
        std::cerr << "No environment variables found" << std::endl;
        return 84;
    }

    if (argc != 2) {
        std::cerr << "Usage: ./arcade <path_to_graphic_library>" << std::endl;
        return 84;
    }

    return !core::Core().run(argv[1]) * 84;
}
