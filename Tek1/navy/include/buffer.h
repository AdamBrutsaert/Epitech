/*
** EPITECH PROJECT, 2023
** buffer.h
** File description:
** buffer.h
*/

#pragma once

#include <stdint.h>

typedef enum {
    BIT_0 = 0,
    BIT_1 = 1,
    BIT_NONE = 2,
} bit_t;

typedef struct {
    bit_t *bits;
    uint64_t capacity;
    uint64_t length;
} buffer_t;

buffer_t *buffer_create(void);
void buffer_destroy(buffer_t *buffer);

uint64_t buffer_get_length(buffer_t *buffer);

int8_t buffer_push(buffer_t *buffer, bit_t bit);
bit_t buffer_pop(buffer_t *buffer);
