/*
** EPITECH PROJECT, 2022
** vec2i.h
** File description:
** vec2i.h
*/

#pragma once

#include <stdint.h>

typedef struct {
    int32_t x;
    int32_t y;
} vec2i_t;

vec2i_t vec2i_add(vec2i_t a, vec2i_t b);
vec2i_t vec2i_sub(vec2i_t a, vec2i_t b);
