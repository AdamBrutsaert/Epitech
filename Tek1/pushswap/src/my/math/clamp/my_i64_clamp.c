/*
** EPITECH PROJECT, 2022
** my_i64_clamp.c
** File description:
** my_i64_clamp.c
*/

#include "my/math.h"

i64_t my_i64_clamp(i64_t number, i64_t min, i64_t max)
{
    return my_i64_min(my_i64_max(number, min), max);
}
