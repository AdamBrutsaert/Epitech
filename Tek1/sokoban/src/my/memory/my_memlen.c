/*
** EPITECH PROJECT, 2022
** my_memlen.c
** File description:
** my_memlen.c
*/

#include "my/memory.h"

u64_t my_memlen(void *ptr)
{
    return *((u64_t*)ptr - 1);
}
