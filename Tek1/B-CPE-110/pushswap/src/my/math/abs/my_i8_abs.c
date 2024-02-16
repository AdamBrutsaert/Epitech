/*
** EPITECH PROJECT, 2022
** my_i8_abs.c
** File description:
** my_i8_abs.c
*/

#include "my/math.h"

i8_t my_i8_abs(i8_t number)
{
    return number < 0 ? -number : number;
}
