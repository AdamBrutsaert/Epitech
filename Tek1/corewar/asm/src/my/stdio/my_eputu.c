/*
** EPITECH PROJECT, 2023
** my_eputu.c
** File description:
** my_eputu.c
*/

#include "my/stdio.h"

void my_eputu(uintmax_t nb)
{
    if (nb >= 10)
        my_eputu(nb / 10);
    my_eputc('0' + nb % 10);
}
