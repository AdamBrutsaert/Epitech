/*
** EPITECH PROJECT, 2022
** my_pow.c
** File description:
** Implementation of my_pow
*/

#include "my.h"

intmax_t my_pow(intmax_t nb, intmax_t p)
{
    intmax_t number = 1;

    for (; p; p--)
        number *= nb;
    return number;
}
