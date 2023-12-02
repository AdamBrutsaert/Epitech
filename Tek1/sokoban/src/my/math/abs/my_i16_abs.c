/*
** EPITECH PROJECT, 2022
** my_i16_abs.c
** File description:
** my_i16_abs.c
*/

#include "my/math.h"

i16_t my_i16_abs(i16_t number)
{
    return number < 0 ? -number : number;
}
