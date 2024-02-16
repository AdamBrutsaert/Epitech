/*
** EPITECH PROJECT, 2022
** vector.h
** File description:
** vector.h
*/

#pragma once

#include "types.h"

typedef struct {
    void *values;
    u64_t stride;
    u64_t length;
    u64_t capacity;
} vector_t;

void vector_create(vector_t *vector, u64_t stride);
void vector_destroy(vector_t *vector);

status_t vector_push(vector_t *vector, void *value);
void vector_pop(vector_t *vector);
void vector_clear(vector_t *vector);

u64_t vector_find(vector_t *vector, void *value);
status_t vector_remove(vector_t *vector, u64_t index);

void *vector_get(vector_t *vector, u64_t index);
status_t vector_set(vector_t *vector, u64_t index, void *value);

status_t vector_reserve(vector_t *vector, u64_t capacity);
status_t vector_fit(vector_t *vector);
