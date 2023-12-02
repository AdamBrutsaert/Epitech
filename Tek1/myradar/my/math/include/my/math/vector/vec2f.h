/*
** EPITECH PROJECT, 2022
** vec2f.h
** File description:
** vec2f.h
*/

#pragma once

typedef struct {
    float x;
    float y;
} vec2f_t;

vec2f_t vec2f_add(vec2f_t a, vec2f_t b);
vec2f_t vec2f_sub(vec2f_t a, vec2f_t b);
vec2f_t vec2f_mul(vec2f_t vector, float factor);
float vec2f_dot(vec2f_t vector, vec2f_t other);

float vec2f_length(vec2f_t vector);
vec2f_t vec2f_normalize(vec2f_t vector);
