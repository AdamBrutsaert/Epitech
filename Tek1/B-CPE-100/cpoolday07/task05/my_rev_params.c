/*
** EPITECH PROJECT, 2022
** my_rev_params
** File description:
** Implementation of my_rev_params
*/

#include "my.h"

int main(int argc, char **argv)
{
    for (; argc; argc--) {
        my_putstr(argv[argc - 1]);
        my_putchar('\n');
    }
}
