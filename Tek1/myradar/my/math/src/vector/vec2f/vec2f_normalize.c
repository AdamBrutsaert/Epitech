/*
** EPITECH PROJECT, 2022
** vec2f_normalize.c
** File description:
** vec2f_normalize.c
*/

#include "my/math/vector/vec2f.h"

vec2f_t vec2f_normalize(vec2f_t vector)
{
    register float length = vec2f_length(vector);

    if (length == 0)
        return vector;
    return ((vec2f_t){vector.x / length, vector.y / length});
}
