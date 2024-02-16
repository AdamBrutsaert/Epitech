/*
** EPITECH PROJECT, 2022
** vector.h
** File description:
** vector.h
*/

#pragma once

#include "my/vector.h"

struct vector_s {
    void *data;
    uint64_t stride;
    uint64_t length;
    uint64_t capacity;
};
