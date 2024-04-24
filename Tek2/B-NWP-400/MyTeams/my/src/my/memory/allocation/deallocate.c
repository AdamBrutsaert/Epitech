/*
** EPITECH PROJECT, 2024
** deallocate.c
** File description:
** deallocate.c
*/

#include "my/memory/allocation.h"

#include <stdlib.h>

void deallocate(void *memory)
{
    free(memory);
}
