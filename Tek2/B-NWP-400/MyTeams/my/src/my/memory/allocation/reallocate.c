/*
** EPITECH PROJECT, 2024
** reallocate.c
** File description:
** reallocate.c
*/

#include "my/memory/allocation.h"

#include <stdlib.h>

void *reallocate(void *memory, size_t bytes)
{
    if (bytes == 0) {
        free(memory);
        return nullptr;
    }
    memory = realloc(memory, bytes);
    if (memory == nullptr)
        exit(84);
    return memory;
}
