/*
** EPITECH PROJECT, 2024
** file_create.c
** File description:
** file_create.c
*/

#include "my/memory/file.h"
#include "my/memory/allocation.h"

file_t *file_create(void)
{
    file_t *self = allocate(sizeof(file_t));

    *self = -1;
    return self;
}
