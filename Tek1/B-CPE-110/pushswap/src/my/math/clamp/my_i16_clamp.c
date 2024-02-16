/*
** EPITECH PROJECT, 2022
** my_i16_clamp.c
** File description:
** my_i16_clamp.c
*/

#include "my/math.h"

i16_t my_i16_clamp(i16_t number, i16_t min, i16_t max)
{
    return my_i16_min(my_i16_max(number, min), max);
}
