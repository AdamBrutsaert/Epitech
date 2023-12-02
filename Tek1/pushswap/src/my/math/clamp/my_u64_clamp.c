/*
** EPITECH PROJECT, 2022
** my_u64_clamp.c
** File description:
** my_u64_clamp.c
*/

#include "my/math.h"

u64_t my_u64_clamp(u64_t number, u64_t min, u64_t max)
{
    return my_u64_min(my_u64_max(number, min), max);
}
