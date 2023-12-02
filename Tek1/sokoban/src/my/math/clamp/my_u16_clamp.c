/*
** EPITECH PROJECT, 2022
** my_u16_clamp.c
** File description:
** my_u16_clamp.c
*/

#include "my/math.h"

u16_t my_u16_clamp(u16_t number, u16_t min, u16_t max)
{
    return my_u16_min(my_u16_max(number, min), max);
}
