/*
** EPITECH PROJECT, 2022
** format.h
** File description:
** Header of format
*/

#pragma once

#include "parsing/format.h"

typedef struct {
    int length;
    uint8_t flags;
    int width;
    int precision;
    value_t *value;
} format_t;
