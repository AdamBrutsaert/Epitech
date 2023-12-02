/*
** EPITECH PROJECT, 2022
** my_free.c
** File description:
** my_free.c
*/

#include "my/memory.h"

#include <stdlib.h>

void my_free(void *ptr)
{
    free((uint64_t *)ptr - !!ptr);
}
