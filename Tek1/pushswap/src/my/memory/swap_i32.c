/*
** EPITECH PROJECT, 2022
** swap_i32.c
** File description:
** swap_i32.c
*/

#include "my/memory.h"

void swap_i32(i32_t *a, i32_t *b)
{
    i32_t copy = *a;

    *a = *b;
    *b = copy;
}
