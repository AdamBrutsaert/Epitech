/*
** EPITECH PROJECT, 2022
** vec2f_dot.c
** File description:
** vec2f_dot.c
*/

#include "my/math/vector/vec2f.h"

float vec2f_dot(vec2f_t vector, vec2f_t other)
{
    return vector.x * other.x + vector.y * other.y;
}
