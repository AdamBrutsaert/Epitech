/*
** EPITECH PROJECT, 2022
** file_create.c
** File description:
** file_create.c
*/

#include "my/file.h"

#include <fcntl.h>
#include <sys/stat.h>

status_t file_create(file_t *file, char const *name)
{
    struct stat stats;

    if (stat(name, &stats) == -1)
        return 84;
    if (!S_ISREG(stats.st_mode) || !(stats.st_mode & S_IRUSR))
        return 84;
    file->name = name;
    file->size = stats.st_size;
    file->fd = open(name, O_RDONLY);
    return 0;
}
