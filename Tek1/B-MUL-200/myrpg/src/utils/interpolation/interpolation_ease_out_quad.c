/*
** EPITECH PROJECT, 2023
** interpolation_ease_out_quad.c
** File description:
** interpolation_ease_out_quad.c
*/

#include "utils/interpolation.h"

float interpolation_ease_out_quad(float x)
{
    return 1 - (1 - x) * (1 - x);
}
