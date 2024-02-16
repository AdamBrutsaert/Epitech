/*
** EPITECH PROJECT, 2023
** file.h
** File description:
** file.h
*/

#pragma once

#include <stdint.h>

typedef struct file_s file_t;

file_t *file_create(char const *filepath);
void file_destroy(file_t *file);

int64_t file_read(file_t *file, char *buffer, int64_t bytes);
uint64_t file_length(file_t *file);
