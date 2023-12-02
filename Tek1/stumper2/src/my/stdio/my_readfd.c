/*
** EPITECH PROJECT, 2023
** my_readfd.c
** File description:
** my_readfd.c
*/

#include "my/stdio.h"
#include "my/memory.h"

#include <unistd.h>
#include <stdbool.h>

static bool realloc_buffer(char **buffer, size_t *capacity)
{
    char *new = my_realloc(*buffer, (*capacity * 2 + 1) * sizeof(char));

    if (new == NULL)
        return false;
    *capacity *= 2;
    *buffer = new;
    return true;
}

char *my_readfd(int fd)
{
    char *buffer = my_malloc(sizeof(char) * 64 + 1);
    size_t length = 0;
    size_t capacity = 64;
    ssize_t bytes_read = 0;

    do {
        length += bytes_read;
        if (length == capacity && !realloc_buffer(&buffer, &capacity)) {
            my_free(buffer);
            return NULL;
        }
        bytes_read = read(fd, buffer + length, capacity - length);
    } while (bytes_read > 0);
    if (bytes_read == -1) {
        my_free(buffer);
        return NULL;
    }
    buffer[length] = '\0';
    return buffer;
}
