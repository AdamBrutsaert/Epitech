/*
** EPITECH PROJECT, 2023
** my_puti.c
** File description:
** my_puti.c
*/

#include "my/stdio.h"

static intmax_t my_abs(intmax_t number)
{
    return number < 0 ? -number : number;
}

void my_puti(intmax_t number)
{
    if (number < 0)
        my_putc('-');
    if (number >= 10 || number <= -10)
        my_puti(my_abs(number / 10));
    my_putc(my_abs(number % 10) + '0');
}
