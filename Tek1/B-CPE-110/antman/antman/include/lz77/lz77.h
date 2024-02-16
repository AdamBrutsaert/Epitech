/*
** EPITECH PROJECT, 2023
** lz77.h
** File description:
** lz77.h
*/

#pragma once

#include "view.h"

typedef struct {
    view_t *view;
    char *buffer;
    uint64_t length;
} lz77_t;
