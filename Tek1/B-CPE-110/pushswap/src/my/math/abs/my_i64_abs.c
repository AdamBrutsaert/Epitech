/*
** EPITECH PROJECT, 2022
** my_i64_abs.c
** File description:
** my_i64_abs.c
*/

#include "my/math.h"

i64_t my_i64_abs(i64_t number)
{
    return number < 0 ? -number : number;
}
