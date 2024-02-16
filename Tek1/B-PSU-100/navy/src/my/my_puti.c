/*
** EPITECH PROJECT, 2023
** my_puti.c
** File description:
** my_puti.c
*/

#include "my.h"

void my_puti(int64_t number)
{
    if (number < 0)
        my_putc('-');
    if (number <= -10 || number >= 10)
        my_puti(my_abs(number / 10));
    my_putc('0' + my_abs(number % 10));
}
