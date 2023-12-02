/*
** EPITECH PROJECT, 2022
** my_f32_clamp.c
** File description:
** my_f32_clamp.c
*/

#include "my/math.h"

f32_t my_f32_clamp(f32_t number, f32_t min, f32_t max)
{
    return my_f32_min(my_f32_max(number, min), max);
}
