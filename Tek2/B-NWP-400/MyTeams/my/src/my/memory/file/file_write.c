/*
** EPITECH PROJECT, 2024
** file_write.c
** File description:
** file_write.c
*/

#include "my/memory/file.h"

#include <unistd.h>

ssize_t file_write(file_t *self, const void *buffer, size_t length)
{
    return write(*self, buffer, length);
}
