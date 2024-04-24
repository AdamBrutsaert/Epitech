/*
** EPITECH PROJECT, 2024
** file_read.c
** File description:
** file_read.c
*/

#include "my/memory/file.h"

#include <unistd.h>

ssize_t file_read(file_t *self, void *buffer, size_t length)
{
    return read(*self, buffer, length);
}
