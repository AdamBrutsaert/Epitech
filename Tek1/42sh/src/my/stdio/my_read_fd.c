/*
** EPITECH PROJECT, 2023
** my_read_fd.c
** File description:
** my_read_fd.c
*/

#include "my/stdio.h"

#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

static bool realloc_buffer(char **buffer, size_t *capacity)
{
    size_t new_capacity = *capacity * 2 + !(*capacity);
    char *new = realloc(*buffer, new_capacity);

    if (new == NULL)
        return false;
    *buffer = new;
    *capacity = new_capacity;
    return true;
}

char *my_read_fd(int fd)
{
    char *buffer = NULL;
    size_t length = 0;
    size_t capacity = 0;
    ssize_t bytes_read = 0;

    do {
        length += bytes_read;
        if (length == capacity && !realloc_buffer(&buffer, &capacity)) {
            free(buffer);
            return NULL;
        }
        bytes_read = read(fd, buffer + length, capacity - length);
    } while (bytes_read > 0);
    if (bytes_read == -1) {
        free(buffer);
        return NULL;
    }
    buffer[length] = '\0';
    return buffer;
}
