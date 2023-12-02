/*
** EPITECH PROJECT, 2023
** my_abs.c
** File description:
** my_abs.c
*/

#include "my.h"

int64_t my_abs(int64_t value)
{
    return value < 0 ? -value : value;
}
