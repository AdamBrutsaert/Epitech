/*
** EPITECH PROJECT, 2023
** file_destroy.c
** File description:
** file_destroy.c
*/

#include "file.h"
#include "file/file.h"

#include <stdlib.h>
#include <unistd.h>

void file_destroy(file_t *file)
{
    close(file->fd);
    free(file);
}
