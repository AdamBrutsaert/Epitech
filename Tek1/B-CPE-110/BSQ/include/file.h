/*
** EPITECH PROJECT, 2022
** file.h
** File description:
** file.h
*/

#pragma once

#include <stdint.h>

typedef struct {
    int fd;
    char const *path;
    uint64_t length;
} file_t;

int8_t file_open(file_t *file, char const *path);
void file_close(file_t *file);
int8_t file_read(file_t *file, char *buffer);
