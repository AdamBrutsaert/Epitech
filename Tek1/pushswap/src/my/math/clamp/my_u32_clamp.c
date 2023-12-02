/*
** EPITECH PROJECT, 2022
** my_u32_clamp.c
** File description:
** my_u32_clamp.c
*/

#include "my/math.h"

u32_t my_u32_clamp(u32_t number, u32_t min, u32_t max)
{
    return my_u32_min(my_u32_max(number, min), max);
}
