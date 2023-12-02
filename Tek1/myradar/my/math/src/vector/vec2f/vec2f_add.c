/*
** EPITECH PROJECT, 2022
** vec2f_add.c
** File description:
** vec2f_add.c
*/

#include "my/math/vector/vec2f.h"

vec2f_t vec2f_add(vec2f_t a, vec2f_t b)
{
    return ((vec2f_t) {a.x + b.x, a.y + b.y});
}
