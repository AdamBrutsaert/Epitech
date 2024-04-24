/*
** EPITECH PROJECT, 2024
** file_destroy.c
** File description:
** file_destroy.c
*/

#include "my/memory/file.h"
#include "my/memory/allocation.h"

#include <unistd.h>

void file_destroy(file_t *self)
{
    file_close(self);
    deallocate(self);
}
