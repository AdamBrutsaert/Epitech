/*
** EPITECH PROJECT, 2022
** my_f32_abs.c
** File description:
** my_f32_abs.c
*/

#include "my/math.h"

f32_t my_f32_abs(f32_t number)
{
    return number < 0 ? -number : number;
}
