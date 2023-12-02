/*
** EPITECH PROJECT, 2023
** my_calloc.c
** File description:
** my_calloc.c
*/

#include "my/memory.h"

void *my_calloc(size_t bytes)
{
    return my_memset(my_malloc(bytes), 0, bytes);
}
