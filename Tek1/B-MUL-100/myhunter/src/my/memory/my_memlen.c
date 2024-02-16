/*
** EPITECH PROJECT, 2022
** my_memlen.c
** File description:
** my_memlen.c
*/

#include "my.h"

uint64_t my_memlen(void *ptr)
{
    return *((uint64_t*)ptr - 1);
}
