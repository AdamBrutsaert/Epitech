/*
** EPITECH PROJECT, 2022
** my_eprintu.c
** File description:
** my_eprintu.c
*/

#include "my/stdio.h"

void my_eprintu(uint64_t number)
{
    if (number >= 10)
        my_eprintu(number / 10);
    my_eprintc('0' + number % 10);
}
