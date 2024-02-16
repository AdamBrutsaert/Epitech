/*
** EPITECH PROJECT, 2022
** my_i8_clamp.c
** File description:
** my_i8_clamp.c
*/

#include "my/math.h"

i8_t my_i8_clamp(i8_t number, i8_t min, i8_t max)
{
    return my_i8_min(my_i8_max(number, min), max);
}
