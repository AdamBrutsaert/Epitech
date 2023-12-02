/*
** EPITECH PROJECT, 2022
** vector.h
** File description:
** vector.h
*/

#pragma once

#include <stdint.h>

typedef struct vector_s vector_t;

vector_t *vector_create(uint64_t stride);
void vector_destroy(vector_t *vector);

void *vector_data(vector_t *vector);
uint64_t vector_stride(vector_t *vector);
uint64_t vector_length(vector_t *vector);
uint64_t vector_capacity(vector_t *vector);

void *vector_top(vector_t *vector);

void vector_push(vector_t *vector, void *value);
void vector_pop(vector_t *vector);

void *vector_get(vector_t *vector, uint64_t index);
void vector_set(vector_t *vector, uint64_t index, void *value);

void vector_reserve(vector_t *vector, uint64_t capacity);
void vector_fit(vector_t *vector);
