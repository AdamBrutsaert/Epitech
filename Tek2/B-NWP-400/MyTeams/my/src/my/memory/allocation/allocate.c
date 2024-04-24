/*
** EPITECH PROJECT, 2024
** allocate.c
** File description:
** allocate.c
*/

#include "my/memory/allocation.h"

#include <stdlib.h>

void *allocate(size_t bytes)
{
    void *memory = malloc(bytes);

    if (memory == nullptr)
        exit(84);
    return memory;
}
