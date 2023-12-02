/*
** EPITECH PROJECT, 2022
** main
** File description:
** Implementation of main
*/

#include "cat.h"

int main(int argc, char **argv)
{
    int error = 0;

    if (argc < 2)
        return cat_stdin();
    for (int i = 1; i < argc; i++)
        error += cat(argv[i]);
    return error ? 84 : 0;
}
