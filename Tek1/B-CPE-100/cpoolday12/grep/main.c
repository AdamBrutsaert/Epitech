/*
** EPITECH PROJECT, 2022
** main
** File description:
** Implementation of main
*/

#include "grep.h"

int main(int argc, char **argv)
{
    int error = 0;

    if (argc < 2)
        return 84;
    if (argc == 2)
        return grep_stdin(argv[1]);
    for (int i = 2; i < argc; i++)
        error += grep(argv[1], argv[i]);
    return error ? 84 : 0;
}
