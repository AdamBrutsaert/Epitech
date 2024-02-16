/*
** EPITECH PROJECT, 2023
** file_create.c
** File description:
** file_create.c
*/

#include "file.h"
#include "file/file.h"

#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>

file_t *file_create(char const *filepath)
{
    file_t *file = malloc(sizeof(file_t));
    struct stat stats;

    stat(filepath, &stats);
    if (!S_ISREG(stats.st_mode)) {
        free(file);
        return NULL;
    }
    if (file == NULL)
        return NULL;
    file->name = filepath;
    file->fd = open(filepath, O_RDONLY);
    if (file->fd == -1) {
        free(file);
        return NULL;
    }
    return file;
}
