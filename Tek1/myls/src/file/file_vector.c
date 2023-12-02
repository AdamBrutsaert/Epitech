/*
** EPITECH PROJECT, 2022
** file_vector.c
** File description:
** file_vector.c
*/

#include "my/file.h"
#include "my/memory.h"

#include <stddef.h>
#include <stdlib.h>

void file_vector_create(file_vector_t *vector)
{
    vector->files = NULL;
    vector->length = 0;
    vector->capacity = 0;
}

void file_vector_destroy(file_vector_t *vector)
{
    for (uint64_t i = 0; i < vector->length; i++) {
        free(vector->files[i].name);
        free(vector->files[i].path);
    }
    free(vector->files);
}

void file_vector_push(file_vector_t *vector, file_t *file)
{
    if (vector->length == vector->capacity) {
        vector->capacity = vector->capacity * 2 + !vector->capacity;
        vector->files = my_realloc(vector->files,
            vector->capacity * sizeof(file_t),
            vector->length * sizeof(file_t));
    }
    my_memcpy(&vector->files[vector->length], file, sizeof(file_t));
    vector->length++;
}
