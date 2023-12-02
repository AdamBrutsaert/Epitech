/*
** EPITECH PROJECT, 2022
** transformation.h
** File description:
** transformation.h
*/

#pragma once

#include <stdint.h>

typedef enum {
    TRANSLATION,
    SCALE,
    ROTATION,
    REFLECTION
} transformation_type_t;

typedef struct {
    transformation_type_t type;
    float param1;
    float param2;
} transformation_t;

typedef struct {
    transformation_t *transformations;
    uint32_t length;
    uint32_t capacity;
} transformation_vector_t;

transformation_vector_t *transformation_vector_create(void);
void transformation_vector_destroy(transformation_vector_t *vector);

void transformation_vector_push(transformation_vector_t *vector,
    transformation_type_t type, float param1, float param2);
