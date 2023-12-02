/*
** EPITECH PROJECT, 2022
** my_memcpy.c
** File description:
** my_memcpy.c
*/

#include "my/memory.h"

void *my_memcpy(void *dest, void const *src, u64_t n)
{
    return my_memmove(dest, src, n);
}
