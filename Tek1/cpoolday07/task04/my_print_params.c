/*
** EPITECH PROJECT, 2022
** my_print_params
** File description:
** Implementation of my_print_params
*/

#include "my.h"

int main(int argc, char **argv)
{
    for (unsigned int i = 0; i < argc; i++) {
        my_putstr(argv[i]);
        my_putchar('\n');
    }
}
