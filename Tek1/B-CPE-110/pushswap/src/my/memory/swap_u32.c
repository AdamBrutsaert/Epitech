/*
** EPITECH PROJECT, 2022
** swap_u32.c
** File description:
** swap_u32.c
*/

#include "my/memory.h"

void swap_u32(u32_t *a, u32_t *b)
{
    u32_t copy = *a;

    *a = *b;
    *b = copy;
}
