/*
** EPITECH PROJECT, 2023
** vector_impl.h
** File description:
** vector_impl.h
*/

#pragma once

#include "vector.h"

struct vec {
    void *data;
    size_t stride;
    size_t length;
    size_t capacity;
    deleter_t deleter;
};
