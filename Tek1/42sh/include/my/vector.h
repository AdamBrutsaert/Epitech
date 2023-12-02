/*
** EPITECH PROJECT, 2023
** vector.h
** File description:
** vector.h
*/

#pragma once

#include <stddef.h>
#include <stdbool.h>

#define VEC_GET(vec, index, type) (*(type *)vec_get(vec, index))
#define VEC_PUSH(vec, data) vec_push(vec, &(data))
#define VEC_LEN(vec) vec_get_length(vec)
#define VEC_DATA(vec) vec_get_data(vec)

typedef struct vec vec_t;

typedef void (*deleter_t)(void *);

vec_t *vec_new(size_t stride);
void vec_delete(vec_t *vec);

size_t vec_get_length(vec_t *vec);
void *vec_get_data(vec_t *vec);

bool vec_push(vec_t *vec, const void *data);
void vec_pop(vec_t *vec);
void vec_clear(vec_t *vec);

void vec_pop_and_delete(vec_t *vec, deleter_t deleter);
void vec_clear_and_delete(vec_t *vec, deleter_t deleter);

void *vec_get(vec_t *vec, size_t index);
bool vec_set(vec_t *vec, size_t index, const void *data);
