/*
** EPITECH PROJECT, 2022
** my_i32_clamp.c
** File description:
** my_i32_clamp.c
*/

#include "my/math.h"

i32_t my_i32_clamp(i32_t number, i32_t min, i32_t max)
{
    return my_i32_min(my_i32_max(number, min), max);
}
