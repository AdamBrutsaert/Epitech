/*
** EPITECH PROJECT, 2022
** my_u8_clamp.c
** File description:
** my_u8_clamp.c
*/

#include "my/math.h"

u8_t my_u8_clamp(u8_t number, u8_t min, u8_t max)
{
    return my_u8_min(my_u8_max(number, min), max);
}
