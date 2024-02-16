/*
** EPITECH PROJECT, 2022
** my_eputu.c
** File description:
** my_eputu.c
*/

#include "my/stdio.h"

void my_eputu(uint32_t number)
{
    if (number >= 10)
        my_eputu(number / 10);
    my_eputc('0' + number % 10);
}
