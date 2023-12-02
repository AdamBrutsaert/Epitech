/*
** EPITECH PROJECT, 2023
** my_putu.c
** File description:
** my_putu.c
*/

#include "my/stdio.h"

void my_putu(uintmax_t nb)
{
    if (nb >= 10)
        my_putu(nb / 10);
    my_putc('0' + nb % 10);
}
