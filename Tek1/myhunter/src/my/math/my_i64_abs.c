/*
** EPITECH PROJECT, 2022
** my_i64_abs.c
** File description:
** my_i64_abs.c
*/

#include "my.h"

int64_t my_i64_abs(int64_t number)
{
    return number < 0 ? -number : number;
}
