/*
** EPITECH PROJECT, 2022
** my_abs.c
** File description:
** Implemetation of my_abs
*/

#include "my.h"

intmax_t my_abs(intmax_t a)
{
    return a < 0 ? -a : a;
}
