/*
** EPITECH PROJECT, 2022
** vector.h
** File description:
** vector.h
*/

#pragma once

#include "types.h"

typedef struct {
    u64_t capacity;
    u64_t length;
    u64_t stride;
    void *values;
} vector_t;

void vector_create(vector_t *vector, u64_t stride);
void vector_destroy(vector_t *vector);

status_t vector_push(vector_t *vector, void *value);
void *vector_get(vector_t *vector, u64_t index);
