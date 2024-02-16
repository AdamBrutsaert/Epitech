/*
** EPITECH PROJECT, 2022
** file.h
** File description:
** file.h
*/

#pragma once

#include "my/types.h"

typedef struct {
    char const *name;
    int fd;
    u64_t size;
} file_t;

status_t file_create(file_t *file, char const *name);
void file_destroy(file_t *file);

char *file_read(file_t *file);
