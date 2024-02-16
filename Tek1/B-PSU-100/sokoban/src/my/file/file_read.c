/*
** EPITECH PROJECT, 2022
** file_read.c
** File description:
** file_read.c
*/

#include "my/file.h"
#include "my/memory.h"

#include <unistd.h>

char *file_read(file_t *file)
{
    char *content = my_malloc(file->size + 1);
    i64_t length = 0;
    i64_t result = 0;

    do {
        length += result;
        result = read(file->fd, content, file->size - length);
    } while (result > 0);
    if (result < 0) {
        my_free(content);
        return nullptr;
    }
    content[file->size] = '\0';
    return content;
}
