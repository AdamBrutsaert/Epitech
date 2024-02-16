/*
** EPITECH PROJECT, 2022
** vec2f_length.c
** File description:
** vec2f_length.c
*/

#include "my/math/vector/vec2f.h"

#include <math.h>

float vec2f_length(vec2f_t vector)
{
    return sqrtf(vector.x * vector.x + vector.y * vector.y);
}
