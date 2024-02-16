/*
** EPITECH PROJECT, 2022
** my_i32_abs.c
** File description:
** my_i32_abs.c
*/

#include "my/math.h"

i32_t my_i32_abs(i32_t number)
{
    return number < 0 ? -number : number;
}
