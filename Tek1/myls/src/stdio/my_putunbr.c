/*
** EPITECH PROJECT, 2022
** my_putunbr.c
** File description:
** my_putunbr.c
*/

#include "my/stdio.h"

void my_putunbr(uint64_t nb)
{
    if (nb >= 10)
        my_putunbr(nb / 10);
    my_printc('0' + nb % 10);
}
