/*
** EPITECH PROJECT, 2022
** my_printu.c
** File description:
** my_printu.c
*/

#include "my/stdio.h"

void my_printu(u64_t number)
{
    if (number >= 10)
        my_printu(number / 10);
    my_printc('0' + number % 10);
}
