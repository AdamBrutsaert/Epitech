/*
** EPITECH PROJECT, 2024
** file_write_all.c
** File description:
** file_write_all.c
*/

#include "my/memory/file.h"

ssize_t file_write_all(file_t *self, const void *buffer, size_t length)
{
    ssize_t written = 0;
    size_t total = 0;

    do {
        written = file_write(self, buffer + total, length - total);
        if (written == -1)
            return total;
        total += written;
    } while (total < length);
    return total;
}
