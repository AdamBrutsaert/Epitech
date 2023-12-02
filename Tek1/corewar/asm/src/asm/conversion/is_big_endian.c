/*
** EPITECH PROJECT, 2023
** is_big_endian.c
** File description:
** is_big_endian.c
*/

#include "asm/compiler_impl.h"

bool is_big_endian(void)
{
    volatile int x = 1;

    return *(char *)&x == 0;
}
