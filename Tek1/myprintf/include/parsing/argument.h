/*
** EPITECH PROJECT, 2022
** argument.h
** File description:
** Header of argument
*/

#pragma once

#include "variant.h"

typedef struct {
    type_t type;
    int32_t index;
} argument_t;

typedef struct {
    argument_t *args;
    uint32_t length;
    uint32_t capacity;
} argument_array_t;

argument_array_t *argument_array_create(void);
void argument_array_destroy(argument_array_t *array);
void argument_array_set(argument_array_t *array, uint32_t index, type_t type);
