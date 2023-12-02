/*
** EPITECH PROJECT, 2022
** vec2f_mul.c
** File description:
** vec2f_mul.c
*/

#include "my/math/vector/vec2f.h"

vec2f_t vec2f_mul(vec2f_t vector, float factor)
{
    return ((vec2f_t){vector.x * factor, vector.y * factor});
}
