/*
** EPITECH PROJECT, 2022
** vec2i_add.c
** File description:
** vec2i_add.c
*/

#include "my/math/vector/vec2i.h"

vec2i_t vec2i_add(vec2i_t a, vec2i_t b)
{
    return ((vec2i_t) {a.x + b.x, a.y + b.y});
}
