/*
** EPITECH PROJECT, 2023
** file_length.c
** File description:
** file_length.c
*/

#include "file.h"
#include "file/file.h"

#include <sys/stat.h>

uint64_t file_length(file_t *file)
{
    struct stat stats;

    stat(file->name, &stats);
    return stats.st_size;
}
