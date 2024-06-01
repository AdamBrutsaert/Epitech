/*
** EPITECH PROJECT, 2024
** main.cpp
** File description:
** main.cpp
*/

#include "nts/State.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
        return 84;

    try {
        nts::run(argv[1]);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    } catch (...) {
        std::cerr << "Unknown error" << std::endl;
        return 84;
    }

    return 0;
}
