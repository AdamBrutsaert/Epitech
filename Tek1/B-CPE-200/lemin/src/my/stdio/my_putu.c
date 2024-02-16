/*
** EPITECH PROJECT, 2023
** my_putu.c
** File description:
** my_putu.c
*/

#include "my/stdio.h"

void my_putu(uintmax_t number)
{
    if (number >= 10)
        my_putu(number / 10);
    my_putc(number % 10 + '0');
}
